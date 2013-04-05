/************************************************************
I understand and have abided by the UNCG Academic Integrity
Policy:	Andrew Holman
*************************************************************
*************************************************************
Homework #4
Dr. Fu
CSC 330-01
Spring 2010
************************************************************/

#include "d_graph.h"
#include "d_except.h"
#include "d_pqueue.h"
#include "d_heap.h"
#include "d_util.h"
#include <set>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

	graph<char> adj_mat;
	set<char> edgeSet;

	int i;
	ifstream fin;
	fin.open("ga.dat");
	if (!fin)
	{
		cerr << "Cannot open 'ga.dat'" << endl;
		exit(1);
	}
	fin >> i;
	char ch, ch1;
	int x;
	for (int j = 0; j < i; j++)
	{
		fin >> ch;
		adj_mat.insertVertex(ch);
	}
	fin >> i;
	for (int j = 0; j < i; j++)
	{
		fin >> ch >> ch1 >> x;
		adj_mat.insertEdge(ch, ch1, x);
	}

	edgeSet = adj_mat.getNeighbors('A');
	cout << "A: in-degree " << adj_mat.inDegree('A');
		cout << " out-degree " << adj_mat.outDegree('A');
	cout << "\n\tEdges: B(" << adj_mat.getWeight('A', 'B') << ") C(";
	cout << adj_mat.getWeight('A', 'C') << ")\n";
	cout << endl << endl;
	cout << "B: in-degree " << adj_mat.inDegree('B');
		cout << " out-degree " << adj_mat.outDegree('B');
	cout << "\n\tEdges: D(";
	cout << adj_mat.getWeight('B', 'D') << ")\n";
	cout << endl << endl;
	cout << "C: in-degree " << adj_mat.inDegree('C');
		cout << " out-degree " << adj_mat.outDegree('C');
	cout << "\n\tEdges: A(" << adj_mat.getWeight('C', 'A') << ")\n";
	cout << endl << endl;
	cout << "D: in-degree " << adj_mat.inDegree('D');
		cout << " out-degree " << adj_mat.outDegree('D');
	cout << "\n\tEdges: C(";
	cout << adj_mat.getWeight('D', 'C') << ")\n";
	cout << endl << endl;


	char arr[10] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int j = 0;
	graph<char>::iterator mat_it;
	set<char>::iterator edge_it;
	for (mat_it = adj_mat.begin(); mat_it != adj_mat.end(); mat_it++)
	{
		edgeSet = adj_mat.getNeighbors(arr[j]);
		cout << arr[j] << ": in-degree " << adj_mat.inDegree(arr[j]);
		cout << " out-degree " << adj_mat.outDegree(arr[j]) << endl << endl;
		for (edge_it = edgeSet.begin(); edge_it != edgeSet.begin(); edge_it++)
		{
			int i = 0;
			cout << arr[j] << " and " << *edge_it << ": " << adj_mat.getWeight(arr[j], *edge_it);
			cout << endl << endl;
			i++;
		}
		j++;
	}
	return 0;
}
