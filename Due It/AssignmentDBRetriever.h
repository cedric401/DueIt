#pragma once
class AssignmentDBRetriever
{
public:
	AssignmentDBRetriever();
	~AssignmentDBRetriever();

private:
	void createEntry();
	void deleteEntry();
	void updateEntry();
	void readEntry(int row);
};

