#include <iostream>
#include <vector>
using namespace std;


class cell
{
public:

    int value;
    bool freeToPass = true;
};

void setSize(int & rowSet , int & columnSet)
{
    cout << "Enter How Many Row You Want? " << endl;
    cin >> rowSet;
    cout << "Enter How Many Column You Want? " << endl;
    cin >> columnSet;
}
void printMatrix(vector< vector<cell> > matrix , int column , int row)
{
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++)
        {
            cout << matrix[i][j].value << "   ";
        }
        cout << endl;
    }
}
void setMatrixField(vector< vector<cell> > &matrix , int row , int column , int & plus , int & minus)
{
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++)
        {
            cout << "This is Column: " << j << " and Row: " << i  << " and Enter \"" << 0 << "\" if You Want to Block This Place or Input Some Other Number for Keeping Open: ";
            int input;
            cin >> input;
            if (input == 0)
            {
                matrix[i][j].value = 0;
                minus++;
            }
            else
            {
                matrix[i][j].value = 1;
                plus++;
            }
            cout << endl;
        }
        printMatrix(matrix , column , i + 1);
    }

}
void setStartAndEnd(vector< vector<cell> > matrix , int & startRow , int & startColumn , int & endRow , int & endColumn
        , int plus)
{
    /// Start
    while (plus > 0)
    {
        cout << "What Row Do You Want to Start: " << endl;
        cin >> startRow;
        cout << endl;
        cout << "What Column Do You Want to Start: " << endl;
        cin >> startColumn;
        if (matrix[startRow][startColumn].value == 1)
        {
            cout << "Well Done! You are Starting from ["<< startRow << "][" << startColumn << "] " << endl;
            break;
        }
        else
        {
            cout << "You Can't Start from Block Places!!!" << endl << "Enter Again" << endl;
        }
    }
    /// End
    while (plus > 0)
    {
        cout << "What Row Do You Want to End: " << endl;
        cin >> endRow;
        cout << endl;
        cout << "What Column Do You Want to End: " << endl;
        cin >> endColumn;
        if (matrix[endRow][endColumn].value == 1 )
        {
            cout << "Well Done! You will Finish at ["<< endRow << "][" << endColumn << "] " << endl;
            break;
        }
        else
        {
            cout << "There might be two problems" << endl << "1.You Can't Start from Block Places!" << "or" << "2. We can't move to left or down!" << endl;
        }
    }
    if (plus = 0)
    {
        cout << "There is no free way in the matrix!" << endl;
    }
}
int findShortestWay (vector< vector<cell> > map , int startRow , int startColumn , int endRow , int endColumn)
{
    if (startRow == endRow && startColumn == endColumn)
    {
        return 0;
    }
    if (startRow < 0
            || startRow > map.size() - 1
            || startColumn < 0
            || startColumn > map[0].size() - 1
            || !map[startRow][startColumn].freeToPass
            || map[startRow][startColumn].value == 0)
    {
        return -1;
    }

    map[startRow][startColumn].freeToPass = false;
    vector <int> pathCollection;
    pathCollection.push_back(findShortestWay(map , startRow + 1 , startColumn , endRow , endColumn));
    pathCollection.push_back(findShortestWay(map , startRow , startColumn + 1 , endRow , endColumn));
    pathCollection.push_back(findShortestWay(map, startRow - 1 , startColumn , endRow , endColumn));
    pathCollection.push_back(findShortestWay(map , startRow , startColumn - 1 , endRow , endColumn));
    int tempPath = map.size() * map[0].size() + 1;
    for (int path : pathCollection)
    {
        if(path != -1 && tempPath > path)
        {
            tempPath = path;
        }
    }
    if (tempPath == map.size() * map[0].size() + 1)
    {
        return -1;
    }
    else
    {
        return tempPath + 1;
    }
}
int main() {
    int row , column;
    setSize(row , column);
    vector< vector<cell> > matrixField (row, vector<cell>  (column));
    int minus = 0 , plus = 0;
    setMatrixField(matrixField , row , column , plus , minus);
    int startRow = 0 , startColumn = 0 , endRow = 0 , endColumn = 0;
    setStartAndEnd(matrixField , startRow , startColumn , endRow , endColumn , plus );
    int finalPath = findShortestWay(matrixField , startRow  , startColumn , endRow , endColumn);
    if (finalPath == -1)
    {
        cout << "there is no way!!" << endl;
    }
    else
    {
        cout << "Shortest Path is : " << finalPath;
    }
    return 0;
}