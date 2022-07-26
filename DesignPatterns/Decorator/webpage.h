#include <memory>
#include <iostream>
#include <string>

struct WebPage
{
    virtual void display()=0;
    virtual ~WebPage() = default;
};

struct BasicWebPage : WebPage
{
    std::string html;
    void display() override
    {
        std::cout << "Basic WEB page html: " << html << std::endl;
    }
};

struct WebPageDecorator : WebPage
{
    WebPageDecorator(std::unique_ptr<WebPage> webPage): _webPage(std::move(webPage))
    {
    }
    void display() override
    {
        _webPage->display();
    }
private:
    std::unique_ptr<WebPage> _webPage;
};

struct AuthenticatedWebPage : WebPageDecorator
{
    AuthenticatedWebPage(std::unique_ptr<WebPage> webPage): 
    WebPageDecorator(std::move(webPage))
    {}

    void authenticateUser()
    {
        std::cout << "authentification done" << std::endl;
    }
    void display() override
    {
        authenticateUser();
        WebPageDecorator::display();
    }
};

struct AuthorizedWebPage : WebPageDecorator
{
    AuthorizedWebPage(std::unique_ptr<WebPage> webPage): 
    WebPageDecorator(std::move(webPage))
    {}

    void authorizedUser()
    {
        std::cout << "authorized done" << std::endl;
    }
    void display() override
    {
        authorizedUser();
        WebPageDecorator::display();
    }
};
