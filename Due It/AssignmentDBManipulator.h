#pragma once
class AssignmentDBManipulator
{
public:
	AssignmentDBManipulator();
	~AssignmentDBManipulator();

private:
	void createEntry();
	void deleteEntry();
	void updateEntry();
	void readEntry(int row);
};

