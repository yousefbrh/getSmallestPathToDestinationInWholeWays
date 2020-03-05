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
void setOutOfRange(int num1 , int num2 , int high , bool & access)
{
    if (num1 < 0)
    {
        num1 = 0;
        access = false;
    }
    if (num1 > high)
    {
        num1 = high;
        access = false;
    }
    if (num2 < 0)
    {
        num2 = 0;
        access = false;
    }
    if (num2 > high)
    {
        num2 = high;
        access = false;
    }
}
void setCondition(int choice , int & i , int & j , int & k , int column , int row)
{
    switch (choice)
    {
        case 1:
            i = 0;
            j = 1;
            k = column - 1;
            break;
        case 2:
            i = 0;
            j = -1;
            k = column - 1;
            break;
        case 3:
            i = 1;
            j = 0;
            k = row - 1;
            break;
        case 4:
            i = -1;
            j = 0;
            k = row - 1;
            break;
    }
}
void move(vector< vector<cell> > matrix , int & tempRow , int & tempColumn , int endRow , int endColumn
        , int & lastSpot , int & path , int row , int column , vector <int> & pathCollection , int & choice)
{
//    cout << "start    " << tempRow << "   " << tempColumn << endl;
    if (tempRow == endRow && tempColumn == endColumn)
        {
            pathCollection.push_back(path);
            return;
        }
    int i , j , k;
    setCondition(choice , i , j , k , column , row);
    bool outOfRangeAccess = true;
    setOutOfRange(tempRow + i , tempColumn + j , k , outOfRangeAccess);
//    cout << "after set    " << tempRow << "   " << tempColumn << endl;
    int xTempRow = tempRow , xTempColumn = tempColumn , xLastSpot = lastSpot , xPath = path;
    if (outOfRangeAccess && matrix[tempRow + i][tempColumn + j].id != lastSpot
    && matrix[tempRow + i][tempColumn + j].value != 0 && matrix[tempRow + i][tempColumn + j].freeToPass)
    {
//        cout << "inside if    " << tempRow << "   " << tempColumn << endl;
        lastSpot = matrix[tempRow][tempColumn].id;
        matrix[tempRow][tempColumn].freeToPass = false;
        tempRow = tempRow + i;
        tempColumn = tempColumn + j;
        path++;
        int ychoice= choice;
//        cout << "after change    " << tempRow << "   " << tempColumn << endl;
        choice = 1;
        move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column
                , pathCollection , choice);
//        cout << "out of if recursive   " << tempRow << "   " << tempColumn << endl;
        choice = ychoice;
    }
    tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
    matrix[tempRow][tempColumn].freeToPass = true;
    outOfRangeAccess = true;
    choice++;
    int xchoice = choice;
//    cout << "before inside second recursive    " << tempRow << "   " << tempColumn << endl;
    if (choice <= 4)
    {
        move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column
                , pathCollection , choice);
        choice = xchoice;
    }
//    cout << "out of second recursive    " << tempRow << "   " << tempColumn << endl;

}
void getSmallestPathToDestination(vector< vector<cell> > matrix , int startRow , int startColumn , int endRow
        , int endColumn , int row , int column)
{
    int path = 0;
    int tempRow = startRow , tempColumn = startColumn;
    int lastSpot = matrix[tempRow][tempColumn].id;
    vector <int> pathCollection;
    int choice = 1;
    int round = 0;
    move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column
            , pathCollection , choice);
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
    getSmallestPathToDestination(matrixField , startRow , startColumn , endRow , endColumn , row , column);
    return 0;
}