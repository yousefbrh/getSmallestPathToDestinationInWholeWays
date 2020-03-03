#include <iostream>
#include <vector>
using namespace std;


class cell
{
    public:

    int value;
    int id;
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
    int id = 1;
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++)
        {
            matrix[i][j].id = id;
            id++;
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
void setStartAndEnd(vector< vector<cell> > matrix , int & startRow , int & startColumn , int & endRow , int & endColumn , int plus)
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
int setOutOfRange(int num , int low , int high , bool & access)
{
    if (num < low)
    {
        num = low;
        access = false;
    }
    if (num > high)
    {
        num = high;
        access = false;
    }
    return num;
}
void move(vector< vector<cell> > matrix , int & tempRow , int & tempColumn , int endRow , int endColumn , int & lastSpot , int & path , int row , int column , vector <int> & pathCollection)
{
    bool outOfRangeAccess = true;
    if (tempRow == endRow && tempColumn == endColumn)
    {
        pathCollection.push_back(path);
        return;
    }
    int xTempRow = tempRow , xTempColumn = tempColumn , xLastSpot = lastSpot , xPath = path;

    ///Up
    if (matrix[setOutOfRange(tempRow - 1, 0 , row - 1 , outOfRangeAccess)][tempColumn].id != lastSpot
    && matrix[setOutOfRange(tempRow - 1 , 0 , row - 1 , outOfRangeAccess)][tempColumn].value != 0
    && matrix[setOutOfRange(tempRow - 1 , 0 , row - 1 , outOfRangeAccess)][tempColumn].freeToPass
    && outOfRangeAccess)
    {
        lastSpot = matrix[tempRow][tempColumn].id;
        matrix[tempRow][tempColumn].freeToPass = false;
        tempRow--;
        path++;
        move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
    }
    tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
    matrix[tempRow][tempColumn].freeToPass = true;
    outOfRangeAccess = true;

    ///Right
    if (matrix[tempRow][setOutOfRange(tempColumn + 1 , 0 , column - 1 , outOfRangeAccess)].id != lastSpot
    && matrix[tempRow][setOutOfRange(tempColumn + 1 , 0 , column - 1 , outOfRangeAccess)].value != 0
    && matrix[tempRow][setOutOfRange(tempColumn + 1 , 0 , column - 1 , outOfRangeAccess)].freeToPass
    && outOfRangeAccess)
    {
        lastSpot = matrix[tempRow][tempColumn].id;
        matrix[tempRow][tempColumn].freeToPass = false;
        tempColumn++;
        path++;
        move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
    }
    tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
    matrix[tempRow][tempColumn].freeToPass = true;
    outOfRangeAccess = true;

    ///Down
    if (matrix[setOutOfRange(tempRow + 1 , 0 , row - 1 ,outOfRangeAccess)][tempColumn].id != lastSpot
    && matrix[setOutOfRange(tempRow + 1 , 0 , row - 1 ,outOfRangeAccess)][tempColumn].value != 0
    && matrix[setOutOfRange(tempRow + 1 , 0 , row - 1 ,outOfRangeAccess)][tempColumn].freeToPass
    && outOfRangeAccess)
    {
        lastSpot = matrix[tempRow][tempColumn].id;
        matrix[tempRow][tempColumn].freeToPass = false;
        tempRow++;
        path++;
        move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);\
    }
    tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
    matrix[tempRow][tempColumn].freeToPass = true;
    outOfRangeAccess = true;

    ///Left
    if (matrix[tempRow][setOutOfRange(tempColumn - 1 , 0 , column - 1 , outOfRangeAccess)].id != lastSpot
    && matrix[tempRow][setOutOfRange(tempColumn - 1 , 0 , column - 1 , outOfRangeAccess)].value != 0
    && matrix[tempRow][setOutOfRange(tempColumn - 1 , 0 , column - 1 , outOfRangeAccess)].freeToPass
    && outOfRangeAccess)
    {
        lastSpot = matrix[tempRow][tempColumn].id;
        matrix[tempRow][tempColumn].freeToPass = false;
        tempColumn--;
        path++;
        move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
    }
    tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
    matrix[tempRow][tempColumn].freeToPass = true;
    outOfRangeAccess = true;
}
void getSmallestPathToDestination(vector< vector<cell> > matrix , int startRow , int startColumn , int endRow , int endColumn , int row , int column , int plus , int minus)
{
    int path = 0;
    int tempRow = startRow , tempColumn = startColumn;
    int lastSpot = matrix[tempRow][tempColumn].id;
    vector <int> pathCollection;
    move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
    if (pathCollection.size())
    {
        path = pathCollection.at(0);
        int count = 0;
        for (int i = 0; i < pathCollection.size() ; i++)
        {
            if (pathCollection[i] < path)
            {
                path = pathCollection[i];
            }
        }
        for (int i = 0; i < pathCollection.size() ; i++)
        {
            if (pathCollection[i] == path)
            {
                count++;
            }
        }
        cout << "Smallest way is: " << path << endl;
        cout << "Whole small way: " << count << endl;
    }
    else
    {
        cout << "Sorry!" << endl << "There is no way to reach that position" << endl;
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
    getSmallestPathToDestination(matrixField , startRow , startColumn , endRow , endColumn , row , column , plus , minus);
    return 0;
}
