#include "../Factory2/armor.h"

class ArmorBuilderFacade
{
public:
    ArmorBuilderFacade()
    {
        heavyarmor_ = new HeavyArmor();
        mediumarmor_ = new MediumArmor();
        lightarmor_ = new LightArmor();
    }

    ~ArmorBuilderFacade()
    {
        delete heavyarmor_;
        delete mediumarmor_;
        delete lightarmor_;
    }
    
    std::string GetHeavyArmor() { return heavyarmor_->ArmorType; }
    std::string GetMediumArmor() { return mediumarmor_->ArmorType; }
    std::string GetLightArmor() { return lightarmor_->ArmorType; }

private:
    HeavyArmor *heavyarmor_;
    MediumArmor *mediumarmor_;
    LightArmor *lightarmor_;
};