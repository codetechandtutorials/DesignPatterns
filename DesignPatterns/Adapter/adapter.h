struct Hamburger {
	bool hasBun = true;
	bool hasMeat = true;
	bool hasPickle = false;
	bool hasOnion = false;
	bool hasCatchup = false;
	bool hasMustard = false;
	bool hasLettuce = false;
	bool hasTomato = false;
};

// a factory style interface that isn't complete enough to 
// consider options, but here so we have an interface to work with
class HamburgerMaker {
public:
	virtual ~HamburgerMaker() = default;
	Hamburger MakeBurger() {
		Hamburger hamb;
		return hamb;
	}
};


// now lets adapt this to a cheeseburger maker

struct Cheeseburger : Hamburger {
	bool hasCheese = true;
};


// adapted hamburger maker into a cheeseburger maker
class CheeseburgerMaker {
private:
	HamburgerMaker* hbmaker;
public:
	virtual ~CheeseburgerMaker() = default;
	CheeseburgerMaker(HamburgerMaker* hbm) { hbmaker = hbm; }
	Cheeseburger MakeBurger() {
		Cheeseburger cburger = static_cast<Cheeseburger>(hbmaker->MakeBurger());
		return cburger;
	}
};

