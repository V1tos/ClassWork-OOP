#include "Var.h"



Var::Var()
{
	this->intType = 0;
	this->doubleType = 0;
	this->stringType = "";
}

Var::Var(int intType)
{
	this->intType = intType;
	this->doubleType = 0;
	this->stringType = "";
}

Var::Var(double doubleType)
{
	this->doubleType = doubleType;
	this->intType = 0;
	this->stringType = "";
}

Var::Var(string stringType)
{
	this->intType = 0;
	this->doubleType = 0;
	this->stringType = stringType;
}

Var Var::operator+(Var & other)
{

	if (this->intType!=0&&other.doubleType != 0&& other.intType==0&&other.stringType=="")
	{
		
		return (this->intType + int(other.doubleType));
		
	}
	if (this->intType != 0 && other.intType != 0&& other.doubleType == 0 && other.stringType == "") {

		return (this->intType + other.intType);
	}
	if (this->intType != 0 && other.stringType != "" && other.intType == 0 && other.doubleType == 0)
	{

		return (this->intType + atoi(other.stringType.c_str()));

	}




	if (this->stringType != "" && other.stringType == "" && other.doubleType == 0&&other.intType!=0 ) {
		string out_string;
		stringstream convert;
		convert << atoi(this->stringType.c_str()) + other.intType;
		out_string = convert.str();

		return out_string;
	}
	
	if (this->stringType != "" && other.stringType == "" && other.intType == 0 && other.doubleType != 0) {
		string out_string;
		stringstream convert;
		convert << atof(this->stringType.c_str()) + other.doubleType;
		out_string = convert.str();

		return out_string;
	}

	if (this->stringType != "" && other.doubleType == 0 && other.intType == 0 && other.stringType != "") {
		

		string out_string;
		stringstream convert;
		convert << atof(this->stringType.c_str()) + atof(other.stringType.c_str());
		out_string = convert.str();

		return out_string;
	}


	if (this->doubleType != 0 && other.intType != 0 && other.doubleType == 0 && other.stringType == "")
	{

		return (this->doubleType + double(other.intType));

	}
	if (this->doubleType != 0 && other.doubleType != 0 && other.intType == 0 && other.stringType == "") {

		return (this->doubleType + other.doubleType);
	}
	if (this->doubleType != 0 && other.stringType != "" && other.intType == 0 && other.doubleType == 0)
	{

		return (this->doubleType + atof(other.stringType.c_str()));

	}

}

Var Var::operator-(Var & other)
{

	if (this->intType != 0 && other.doubleType != 0 && other.intType == 0 && other.stringType == "")
	{

		return (this->intType - int(other.doubleType));

	}
	if (this->intType != 0 && other.intType != 0 && other.doubleType == 0 && other.stringType == "") {

		return (this->intType - other.intType);
	}
	if (this->intType != 0 && other.stringType != "" && other.intType == 0 && other.doubleType == 0)
	{

		return (this->intType - atof(other.stringType.c_str()));

	}






	if (this->stringType != "" && other.stringType == "" && other.doubleType == 0 && other.intType != 0) {
		string out_string;
		stringstream convert;
		convert << atof(this->stringType.c_str()) - other.intType;
		out_string = convert.str();

		return out_string;
	}

	if (this->stringType != "" && other.stringType == "" && other.intType == 0 && other.doubleType != 0) {
		string out_string;
		stringstream convert;
		convert << atof(this->stringType.c_str()) - other.doubleType;
		out_string = convert.str();

		return out_string;
	}

	if (this->stringType != "" && other.doubleType == 0 && other.intType == 0 && other.stringType != "") {


		string out_string;
		stringstream convert;
		convert << atof(this->stringType.c_str()) - atof(other.stringType.c_str());
		out_string = convert.str();

		return out_string;
	}






	if (this->doubleType != 0 && other.intType != 0 && other.doubleType == 0 && other.stringType == "")
	{

		return (this->doubleType - double(other.intType));

	}
	if (this->doubleType != 0 && other.doubleType != 0 && other.intType == 0 && other.stringType == "") {

		return (this->doubleType - other.doubleType);
	}
	if (this->doubleType != 0 && other.stringType != "" && other.intType == 0 && other.doubleType == 0)
	{

		return (this->doubleType - atof(other.stringType.c_str()));

	}
}

Var Var::operator*(Var & other)
{

	if (this->intType != 0 && other.doubleType != 0 && other.intType == 0 && other.stringType == "")
	{

		return (this->intType * int(other.doubleType));

	}
	if (this->intType != 0 && other.intType != 0 && other.doubleType == 0 && other.stringType == "") {

		return (this->intType * other.intType);
	}
	if (this->intType != 0 && other.stringType != "" && other.intType == 0 && other.doubleType == 0)
	{

		return (this->intType * atof(other.stringType.c_str()));

	}






	if (this->stringType != "" && other.stringType == "" && other.doubleType == 0 && other.intType != 0) {
		string out_string;
		stringstream convert;
		convert << atof(this->stringType.c_str()) * other.intType;
		out_string = convert.str();

		return out_string;
	}

	if (this->stringType != "" && other.stringType == "" && other.intType == 0 && other.doubleType != 0) {
		string out_string;
		stringstream convert;
		convert << atof(this->stringType.c_str()) * other.doubleType;
		out_string = convert.str();

		return out_string;
	}

	if (this->stringType != "" && other.doubleType == 0 && other.intType == 0 && other.stringType != "") {


		string out_string;
		stringstream convert;
		convert << atof(this->stringType.c_str()) * atof(other.stringType.c_str());
		out_string = convert.str();

		return out_string;
	}






	if (this->doubleType != 0 && other.intType != 0 && other.doubleType == 0 && other.stringType == "")
	{

		return (this->doubleType * double(other.intType));

	}
	if (this->doubleType != 0 && other.doubleType != 0 && other.intType == 0 && other.stringType == "") {

		return (this->doubleType * other.doubleType);
	}
	if (this->doubleType != 0 && other.stringType != "" && other.intType == 0 && other.doubleType == 0)
	{

		return (this->doubleType * atof(other.stringType.c_str()));

	}
}

Var Var::operator/(Var & other)
{
	if (this->intType != 0 && other.doubleType != 0 && other.intType == 0 && other.stringType == "")
	{

		return (this->intType / int(other.doubleType));

	}
	if (this->intType != 0 && other.intType != 0 && other.doubleType == 0 && other.stringType == "") {

		return (this->intType / other.intType);
	}
	if (this->intType != 0 && other.stringType != "" && other.intType == 0 && other.doubleType == 0)
	{

		return (this->intType / atof(other.stringType.c_str()));

	}






	if (this->stringType != "" && other.stringType == "" && other.doubleType == 0 && other.intType != 0) {
		string out_string;
		stringstream convert;
		convert << atof(this->stringType.c_str()) / other.intType;
		out_string = convert.str();

		return out_string;
	}

	if (this->stringType != "" && other.stringType == "" && other.intType == 0 && other.doubleType != 0) {
		string out_string;
		stringstream convert;
		convert << atof(this->stringType.c_str()) / other.doubleType;
		out_string = convert.str();

		return out_string;
	}

	if (this->stringType != "" && other.doubleType == 0 && other.intType == 0 && other.stringType != "") {


		string out_string;
		stringstream convert;
		convert << atof(this->stringType.c_str()) / atof(other.stringType.c_str());
		out_string = convert.str();

		return out_string;
	}






	if (this->doubleType != 0 && other.intType != 0 && other.doubleType == 0 && other.stringType == "")
	{

		return (this->doubleType / double(other.intType));

	}
	if (this->doubleType != 0 && other.doubleType != 0 && other.intType == 0 && other.stringType == "") {

		return (this->doubleType / other.doubleType);
	}
	if (this->doubleType != 0 && other.stringType != "" && other.intType == 0 && other.doubleType == 0)
	{

		return (this->doubleType / atof(other.stringType.c_str()));

	}
}

void Var::ShowVar()
{
	if (this->intType > 0&&this->doubleType==0&&this->stringType=="") {
		
		cout << "Int - " << this->intType << endl;
	}
	else if (this->doubleType > 0 && this->intType == 0 && this->stringType == "") {
		cout << "Double - " << this->doubleType << endl;
	}
	else
	{
		cout << "String - " << this->stringType << endl;
	}
}


Var::~Var()
{
}
