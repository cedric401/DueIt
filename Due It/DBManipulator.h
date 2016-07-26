#pragma once
#include "BillsDBManipulator.h"
#include "AssignmentDBManipulator.h"
class DBManipulator
{
public:
	DBManipulator();
	~DBManipulator();
	BillsDBManipulator billsDB;
	AssignmentDBManipulator assignmentDB;
};

