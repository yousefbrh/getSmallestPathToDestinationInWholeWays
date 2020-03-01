#include <iostream>
#include <vector>
using namespace std;


void setSize(int & rowSet , int & columnSet)
{
    cout << "Enter How Many Row You Want? " << endl;
    cin >> rowSet;
    cout << "Enter How Many Column You Want? " << endl;
    cin >> columnSet;
}
void printMatrix(vector< vector<int> > matrix , int column , int row)
{
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++)
        {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}
void setMatrixField(vector< vector<int> > &matrix , int row , int column , int & plus , int & minus)
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
                matrix[i][j] = 0;
                minus++;
            }
            else
            {
                matrix[i][j] = 1;
                plus++;
            }
            cout << endl;
        }
        printMatrix(matrix , column , i + 1);
    }
}
void setStartAndEnd(vector< vector<int> > matrix , int & startRow , int & startColumn , int & endRow , int & endColumn , int plus)
{
    /// Start
    while (plus > 0)
    {
        cout << "What Row Do You Want to Start: " << endl;
        cin >> startRow;
        cout << endl;
        cout << "What Column Do You Want to Start: " << endl;
        cin >> startColumn;
        if (matrix[startRow][startColumn] == 1)
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
        if (matrix[endRow][endColumn] == 1 )
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
//int move(vector< vector<int> > matrix , int & tempRow , int & tempColumn , int endRow , int endColumn , int & path , int & lastSpotRow , int & lastSpotColumn)
//{
//    int ways , da
//}
int move(vector< vector<int> > matrix , int & tempRow , int & tempColumn , int endRow , int endColumn , int & path , int & lastSpotRow , int & lastSpotColumn , int row , int column)
{
    cout << "check start " << tempRow << "   " << tempColumn << "   "<<path << endl;
    cout << "enter move" << endl;
    cout << tempRow << "   " << tempColumn << "   "<< path << endl;
    cout << lastSpotRow << "   " << lastSpotColumn << endl;
    if (tempRow == endRow && tempColumn == endColumn)
    {
        cout << "enter move 1" << endl;
        cout <<"answer :" << path << endl;
        return 0;
    }
    cout << "enter move 2" << endl;
    if (tempRow != 0)
    {
        cout << "enter move 2/1" << endl;
        cout << tempRow << "   " << tempColumn << endl;
        int xTempRow = tempRow , xTempColumn = tempColumn , xPath = path , xLastSpotRow = lastSpotRow , xLastSpotColumn = lastSpotColumn;
        if (matrix[tempRow - 1][tempColumn] == 1 && (tempColumn != lastSpotColumn || tempRow - 1 != lastSpotRow))
        {
            cout << "enter move 3" << endl;
            lastSpotRow = tempRow;
            lastSpotColumn = tempColumn;
            tempRow--;
            path++;
            cout << tempRow << "   " << tempColumn << "   "<<path << endl;
            cout << lastSpotRow << "   " << lastSpotColumn << endl;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , path , lastSpotRow , lastSpotColumn , row , column);
        }
        tempRow = xTempRow;
        tempColumn = xTempColumn;
        path = xPath;
        lastSpotRow = xLastSpotRow;
        lastSpotColumn = xLastSpotColumn;
    }
    if (tempColumn != endColumn && tempColumn != column - 1) {
        cout << "enter move 2/2" << endl;
        cout << tempRow << "   " << tempColumn << endl;
        int xTempRow = tempRow, xTempColumn = tempColumn, xPath = path, xLastSpotRow = lastSpotRow , xLastSpotColumn = lastSpotColumn;
        if (matrix[tempRow][tempColumn + 1] == 1 && (tempColumn + 1 != lastSpotColumn || tempRow != lastSpotRow))
        {
            cout << "enter move 4" << endl;
            lastSpotRow = tempRow;
            lastSpotColumn = tempColumn;
            tempColumn++;
            path++;
            cout << tempRow << "   " << tempColumn << "   "<<path << endl;
            cout << lastSpotRow << "   " << lastSpotColumn << endl;
            move(matrix, tempRow, tempColumn, endRow, endColumn, path, lastSpotRow, lastSpotColumn, row, column);
        }
        tempRow = xTempRow;
        tempColumn = xTempColumn;
        path = xPath;
        lastSpotRow = xLastSpotRow;
        lastSpotColumn = xLastSpotColumn;
    }
    if (tempRow != endRow && tempRow != row - 1)
    {
        cout << "enter move 2/3" << endl;
        cout << tempRow << "   " << tempColumn << endl;
        cout << lastSpotRow << "   " << lastSpotColumn << endl;
        int xTempRow = tempRow , xTempColumn = tempColumn , xPath = path , xLastSpotRow = lastSpotRow , xLastSpotColumn = lastSpotColumn;
        if (matrix[tempRow + 1][tempColumn] == 1 && (tempColumn != lastSpotColumn || tempRow + 1 != lastSpotRow))
        {
            cout << "enter move 5" << endl;
            lastSpotRow = tempRow;
            lastSpotColumn = tempColumn;
            tempRow++;
            path++;
            cout << tempRow << "   " << tempColumn << "   "<<path << endl;
            cout << lastSpotRow << "   " << lastSpotColumn << endl;
            move(matrix, tempRow, tempColumn, endRow, endColumn, path, lastSpotRow, lastSpotColumn, row, column);
        }
        tempRow = xTempRow;
        tempColumn = xTempColumn;
        path = xPath;
        lastSpotRow = xLastSpotRow;
        lastSpotColumn = xLastSpotColumn;
    }
    if (tempColumn != 0)
    {
        cout << "enter move 2/4" << endl;
        cout << tempRow << "   " << tempColumn << endl;
        cout << lastSpotRow << "   " << lastSpotColumn << endl;
        int xTempRow = tempRow , xTempColumn = tempColumn , xPath = path , xLastSpotRow = lastSpotRow , xLastSpotColumn = lastSpotColumn;
        if (matrix[tempRow][tempColumn - 1] == 1 && (tempColumn - 1 != lastSpotColumn || tempRow != lastSpotRow))
        {
            cout << "enter move 6" << endl;
            lastSpotRow = tempRow;
            lastSpotColumn = tempColumn;
            tempColumn--;
            path++;
            cout << tempRow << "   " << tempColumn << "   "<<path << endl;
            cout << lastSpotRow << "   " << lastSpotColumn << endl;
            move(matrix, tempRow, tempColumn, endRow, endColumn, path, lastSpotRow, lastSpotColumn, row, column);
        }
        tempRow = xTempRow;
        tempColumn = xTempColumn;
        path = xPath;
        lastSpotRow = xLastSpotRow;
        lastSpotColumn = xLastSpotColumn;
    }
    cout << "enter move last else" << endl;
    cout << "check end " << tempRow << "   " << tempColumn << "   "<<path << endl;
}
void getSmallestPathToDestination(vector< vector<int> > matrix , int startRow , int startColumn , int endRow , int endColumn , int row , int column , int plus , int minus)
{
    int path = 0;
    int tempRow = startRow , tempColumn = startColumn;
    int lastSpotRow = tempRow , lastSpotColumn = tempColumn;
    move(matrix , tempRow ,tempColumn , endRow , endColumn , path , lastSpotRow , lastSpotColumn , row , column);
}
int main() {
    int row , column;
    setSize(row , column);
    vector< vector<int> > matrixField (row, vector<int>  (column));
    int minus = 0 , plus = 0;
    setMatrixField(matrixField , row , column , plus , minus);
    int startRow = 0 , startColumn = 0 , endRow = 0 , endColumn = 0;
    setStartAndEnd(matrixField , startRow , startColumn , endRow , endColumn , plus );
    getSmallestPathToDestination(matrixField , startRow , startColumn , endRow , endColumn , row , column , plus , minus);
    return 0;
}
