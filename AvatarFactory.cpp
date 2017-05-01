#include <string>
#include <iostream>

using namespace std;

class EyeColor
{
public:
	string eyeColor;
};

class SkinColor
{
public:
	string skinColor;

};


class Avatar
{
public:
	EyeColor* a_eyeColor;
	SkinColor* a_skin_Color;


	void specifications()
	{
		std::cout << "EyeColor:" << a_eyeColor->eyeColor << std::endl;
		std::cout << "SkinColor" << a_skin_Color->skinColor << std::endl;

	}
};

class AvatarBuilder
{
public:

	virtual EyeColor* getEyeColor()=0;
	virtual SkinColor* getSkinColor()=0;
};

class AfricanAvatar :public  AvatarBuilder
{
public:
	virtual EyeColor* getEyeColor()
	{
		EyeColor * E_eyeColor = new EyeColor();
		E_eyeColor->eyeColor = "Brown";
		return E_eyeColor;
	}

	virtual SkinColor* getSkinColor()
	{
		SkinColor * E_skinColor = new SkinColor();
		E_skinColor->skinColor = "Black";
		return E_skinColor;
	}
};

class AmericanAvatar :public AvatarBuilder
{
public:
	virtual EyeColor* getEyeColor()
	{
		EyeColor * E_eyeColor = new EyeColor();
		E_eyeColor->eyeColor = "Blue";
		return E_eyeColor;
	}

	virtual SkinColor* getSkinColor()
	{
		SkinColor * E_skinColor = new SkinColor();
		E_skinColor->skinColor = "White";
		return E_skinColor;
	}
};

class AvatarFactory
{
public:
	static AvatarBuilder * newAvatar(string description)
	{
		if(description == "gana")
			return new AfricanAvatar;
		if(description == "Oregon")
			return new AmericanAvatar;
	}

};

class director
{
public:
	AvatarBuilder * builder;

	void setAvatar(AvatarBuilder * A_builder)
	{
		builder = A_builder;

	}
	
	Avatar* getAvatar()
	{
		Avatar *myAvatar = new Avatar();
		myAvatar->a_eyeColor = builder->getEyeColor();
		myAvatar->a_skin_Color = builder->getSkinColor();
		return myAvatar;
	}

};


void main()
{

	Avatar * avatar;
	AfricanAvatar  Afr_Avatar;
	AmericanAvatar  Amr_Avatar;

	director myDirector;
	myDirector.setAvatar(&Afr_Avatar);
	avatar = myDirector.getAvatar();
	avatar->specifications();
	cout <<endl;
	cout <<" ************" <<endl;

	myDirector.setAvatar(AvatarFactory::newAvatar("Oregon"));

	avatar = myDirector.getAvatar();
	avatar->specifications();

}
