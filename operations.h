#pragma once

class game;
/////////////////////////////////// class operation  //////////////////
//Base class of all operations supported by the application
class operation
{
protected:
	game* pGame;	//pointer to the game class
public:
	operation(game* r_pGame);

	//Function Act:
	//Implements the action that should be taken by this operation
	//Should be overriden by derived classes
	virtual void Act() = 0;
};
/////////////////////////////////// class operAddSign  //////////////////
//Responsible for 
//1- collectign data about a new Sign shape to add
//2- Adding the new shape to the list of shapes (throgh the grid class)
class operAddSign :public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};

class operaddcar :public operation
{
public:
	operaddcar(game* r_pGame);
	virtual void Act();
};


class operaaddrobot :public operation
{
public:
	operaaddrobot(game* r_pGame);
	virtual void Act();
};

class operaddboat :public operation
{
public:
	operaddboat(game* r_pGame);
	virtual void Act();
};

class operaddrocket :public operation
{
public:
	operaddrocket(game* r_pGame);
	virtual void Act();
};

class operaddhome :public operation
{
public:
	operaddhome(game* r_pGame);
	virtual void Act();
};
class operIncrease : public operation
{
public:
	operIncrease(game* r_pGame);
	virtual void Act();
};

class operDecrease : public operation
{
public:
	operDecrease(game* r_pGame);
	virtual void Act();
};

class operRotate : public operation
{
public:
	operRotate(game* r_pGame);
	virtual void Act() override;
};

class operRefresh : public operation
{
public:
	operRefresh(game* r_pGame);
	virtual void Act();
};

class operHint : public operation
{
public:
	operHint(game* r_pGame);
	virtual void Act();
};

class operDelete : public operation
{
public:
	operDelete(game* r_pGame);
	virtual void Act();
};

class operSave : public operation
{
public:
	operSave(game* r_pGame);
	virtual void Act();
};

class operSelect : public operation
{
public:
	operSelect(game* r_pGame);
	virtual void Act();



};


class oppdelete :public operation
{
public:
	oppdelete(game* r_pGame);

};
