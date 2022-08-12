#include <list>
class File {
public:
	virtual ~File() = default;
	virtual void Add(File* file) = 0;
	virtual void Remove(File* file) = 0;
	virtual void SetParent(File* file) {
		throw(-1);
	}
protected:

	File* parent_folder;
};

class Folder : public File {
public:
	void Add(File* file) override {
		children.push_back(file);
		children.back()->SetParent(this);
	}
	void Remove(File* file) override {
		// remove matching file* from list of children
	}
protected:
	std::list<File*> children;
};

class MediaFile : public File {
	void Add(File* file) override {
		// do nothing in this case, can't host more files
	}
	void Remove(File* file) override {
		// doesn't really work in this case, need different methods
		parent_folder->Remove(file);
	}
	void SetParent(File* file) override {
		Folder* cast_check = dynamic_cast<Folder*>(file);
		if (cast_check) {
			this->parent_folder = file;
		}
	}
protected:

};