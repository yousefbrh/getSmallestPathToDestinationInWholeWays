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
void move(vector< vector<cell> > matrix , int & tempRow , int & tempColumn , int endRow , int endColumn , int & lastSpot , int & path , int row , int column , vector <int> & pathCollection)
{
    if (tempRow == endRow && tempColumn == endColumn)
    {
        //cout << "destination" << endl;
        pathCollection.push_back(path);
        return;
    }
    if (tempRow == 0 && tempColumn == 0)
    {
        //cout << "start  " << tempRow << "      " << tempColumn << endl;
        int xTempRow = tempRow , xTempColumn = tempColumn , xLastSpot = lastSpot , xPath = path;
        ///Down
        if (matrix[tempRow + 1][tempColumn].id != lastSpot && matrix[tempRow + 1][tempColumn].value != 0 && matrix[tempRow + 1][tempColumn].freeToPass)
        {
            //cout << "down" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempRow++;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
        matrix[tempRow][tempColumn].freeToPass = true;
        ///Right
        if (matrix[tempRow][tempColumn + 1].id != lastSpot && matrix[tempRow][tempColumn + 1].value != 0 && matrix[tempRow][tempColumn + 1].freeToPass)
        {
            //cout << "right" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempColumn++;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
        matrix[tempRow][tempColumn].freeToPass = true;
        //cout << "end  " << tempRow << "      " << tempColumn << endl;
        return;
    }

    if (tempRow == 0 && tempColumn == column - 1)
    {
        //cout << "start  " << tempRow << "      " << tempColumn << endl;
        int xTempRow = tempRow , xTempColumn = tempColumn , xLastSpot = lastSpot , xPath = path;
        ///Down
        if (matrix[tempRow + 1][tempColumn].id != lastSpot && matrix[tempRow + 1][tempColumn].value != 0 && matrix[tempRow + 1][tempColumn].freeToPass)
        {
            //cout << "down" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempRow++;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
        matrix[tempRow][tempColumn].freeToPass = true;
        ///Left
        if (matrix[tempRow][tempColumn - 1].id != lastSpot && matrix[tempRow][tempColumn - 1].value != 0 && matrix[tempRow][tempColumn - 1].freeToPass)
        {
            //cout << "left" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempColumn--;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
        matrix[tempRow][tempColumn].freeToPass = true;
        //cout << "end  " << tempRow << "      " << tempColumn << endl;
        return;
    }

    if (tempRow == row - 1 && tempColumn == 0)
    {
        //cout << "start  " << tempRow << "      " << tempColumn << endl;
        int xTempRow = tempRow , xTempColumn = tempColumn , xLastSpot = lastSpot , xPath = path;
        ///Up
        if (matrix[tempRow - 1][tempColumn].id != lastSpot && matrix[tempRow - 1][tempColumn].value != 0 && matrix[tempRow - 1][tempColumn].freeToPass)
        {
            //cout << "up" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempRow--;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
        matrix[tempRow][tempColumn].freeToPass = true;
        ///Right
        if (matrix[tempRow][tempColumn + 1].id != lastSpot && matrix[tempRow][tempColumn + 1].value != 0 && matrix[tempRow][tempColumn + 1].freeToPass)
        {
            //cout << "right" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempColumn++;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
        matrix[tempRow][tempColumn].freeToPass = true;
        //cout << "end  " << tempRow << "      " << tempColumn << endl;
        return;
    }

    if (tempRow == row - 1 && tempColumn == column - 1)
    {
        //cout << "start  " << tempRow << "      " << tempColumn << endl;
        int xTempRow = tempRow , xTempColumn = tempColumn , xLastSpot = lastSpot , xPath = path;
        ///Up
        if (matrix[tempRow - 1][tempColumn].id != lastSpot && matrix[tempRow - 1][tempColumn].value != 0 && matrix[tempRow - 1][tempColumn].freeToPass)
        {
            //cout << "up" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempRow--;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
        matrix[tempRow][tempColumn].freeToPass = true;
        ///Left
        if (matrix[tempRow][tempColumn - 1].id != lastSpot && matrix[tempRow][tempColumn - 1].value != 0 && matrix[tempRow][tempColumn - 1].freeToPass)
        {
            //cout << "left" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempColumn--;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
        matrix[tempRow][tempColumn].freeToPass = true;
        //cout << "end  " << tempRow << "      " << tempColumn << endl;
        return;
    }

    if (tempRow == 0 && tempColumn != 0 && tempColumn != column - 1)
    {
        //cout << "start  " << tempRow << "      " << tempColumn << endl;
        int xTempRow = tempRow , xTempColumn = tempColumn , xLastSpot = lastSpot , xPath = path;
        ///Down
        if (matrix[tempRow + 1][tempColumn].id != lastSpot && matrix[tempRow + 1][tempColumn].value != 0 && matrix[tempRow + 1][tempColumn].freeToPass)
        {
            //cout << "down" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempRow++;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
        matrix[tempRow][tempColumn].freeToPass = true;
        ///Right
        if (matrix[tempRow][tempColumn + 1].id != lastSpot && matrix[tempRow][tempColumn + 1].value != 0 && matrix[tempRow][tempColumn + 1].freeToPass)
        {
            //cout << "right" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempColumn++;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
        matrix[tempRow][tempColumn].freeToPass = true;
        ///Left
        if (matrix[tempRow][tempColumn - 1].id != lastSpot && matrix[tempRow][tempColumn - 1].value != 0 && matrix[tempRow][tempColumn - 1].freeToPass)
        {
            //cout << "left" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempColumn--;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
        matrix[tempRow][tempColumn].freeToPass = true;
        //cout << "end  " << tempRow << "      " << tempColumn << endl;
        return ;
    }

    if (tempRow == row - 1 && tempColumn != 0 && tempColumn != column - 1)
    {
        //cout << "start  " << tempRow << "      " << tempColumn << endl;
        int xTempRow = tempRow , xTempColumn = tempColumn , xLastSpot = lastSpot , xPath = path;
        ///Up
        if (matrix[tempRow - 1][tempColumn].id != lastSpot && matrix[tempRow - 1][tempColumn].value != 0 && matrix[tempRow - 1][tempColumn].freeToPass)
        {
            //cout << "up" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempRow--;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
        matrix[tempRow][tempColumn].freeToPass = true;
        ///Right
        if (matrix[tempRow][tempColumn + 1].id != lastSpot && matrix[tempRow][tempColumn + 1].value != 0 && matrix[tempRow][tempColumn + 1].freeToPass)
        {
            //cout << "right" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempColumn++;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
        matrix[tempRow][tempColumn].freeToPass = true;
        ///Left
        if (matrix[tempRow][tempColumn - 1].id != lastSpot && matrix[tempRow][tempColumn - 1].value != 0 && matrix[tempRow][tempColumn - 1].freeToPass)
        {
            //cout << "left" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempColumn--;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
        matrix[tempRow][tempColumn].freeToPass = true;
        //cout << "end  " << tempRow << "      " << tempColumn << endl;
        return ;
    }

    if (tempColumn == column - 1 && tempRow != 0 && tempRow != row - 1)
    {
        //cout << "start  " << tempRow << "      " << tempColumn << endl;
        int xTempRow = tempRow , xTempColumn = tempColumn , xLastSpot = lastSpot , xPath = path;
        ///Up
        if (matrix[tempRow - 1][tempColumn].id != lastSpot && matrix[tempRow - 1][tempColumn].value != 0 && matrix[tempRow - 1][tempColumn].freeToPass)
        {
            //cout << " up" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempRow--;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
        matrix[tempRow][tempColumn].freeToPass = true;
        ///Down
        if (matrix[tempRow + 1][tempColumn].id != lastSpot && matrix[tempRow + 1][tempColumn].value != 0 && matrix[tempRow + 1][tempColumn].freeToPass)
        {
            //cout << "down" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempRow++;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
        matrix[tempRow][tempColumn].freeToPass = true;
        ///Left
        if (matrix[tempRow][tempColumn - 1].id != lastSpot && matrix[tempRow][tempColumn - 1].value != 0 && matrix[tempRow][tempColumn - 1].freeToPass)
        {
            //cout << "left" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempColumn--;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
        matrix[tempRow][tempColumn].freeToPass = true;
        //cout << "end  " << tempRow << "      " << tempColumn << endl;
        return ;
    }

    if (tempColumn == 0 && tempRow != 0 && tempRow != row - 1)
    {
        //cout << "start  " << tempRow << "      " << tempColumn << endl;
        int xTempRow = tempRow , xTempColumn = tempColumn , xLastSpot = lastSpot , xPath = path;
        ///Up
        if (matrix[tempRow - 1][tempColumn].id != lastSpot && matrix[tempRow - 1][tempColumn].value != 0 && matrix[tempRow - 1][tempColumn].freeToPass)
        {
            //cout << "up" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempRow--;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
        matrix[tempRow][tempColumn].freeToPass = true;
        ///Right
        if (matrix[tempRow][tempColumn + 1].id != lastSpot && matrix[tempRow][tempColumn + 1].value != 0 && matrix[tempRow][tempColumn + 1].freeToPass)
        {
            //cout << "right" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempColumn++;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
        matrix[tempRow][tempColumn].freeToPass = true;
        ///Down
        if (matrix[tempRow + 1][tempColumn].id != lastSpot && matrix[tempRow + 1][tempColumn].value != 0 && matrix[tempRow + 1][tempColumn].freeToPass)
        {
            //cout << "down" << endl;
            lastSpot = matrix[tempRow][tempColumn].id;
            matrix[tempRow][tempColumn].freeToPass = false;
            tempRow++;
            path++;
            move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        }
        tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
        matrix[tempRow][tempColumn].freeToPass = true;
        //cout << "end  " << tempRow << "      " << tempColumn << endl;
        return ;
    }

    int xTempRow = tempRow , xTempColumn = tempColumn , xLastSpot = lastSpot , xPath = path;
    ///Up
    if (matrix[tempRow - 1][tempColumn].id != lastSpot && matrix[tempRow - 1][tempColumn].value != 0 && matrix[tempRow - 1][tempColumn].freeToPass)
    {
        //cout << "up" << endl;
        //cout << "start  " << tempRow << "      " << tempColumn << endl;
        lastSpot = matrix[tempRow][tempColumn].id;
        matrix[tempRow][tempColumn].freeToPass = false;
        tempRow--;
        path++;
        move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        //cout << "end  " << tempRow + 1 << "      " << tempColumn << endl;
    }
    tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
    matrix[tempRow][tempColumn].freeToPass = true;
    ///Right
    //cout << "start  " << tempRow << "      " << tempColumn << endl;
    if (matrix[tempRow][tempColumn + 1].id != lastSpot && matrix[tempRow][tempColumn + 1].value != 0 && matrix[tempRow][tempColumn + 1].freeToPass)
    {
        //cout << "right" << endl;
        //cout << "start  " << tempRow << "      " << tempColumn << endl;
        lastSpot = matrix[tempRow][tempColumn].id;
        matrix[tempRow][tempColumn].freeToPass = false;
        tempColumn++;
        path++;
        move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        //cout << "end  " << tempRow << "      " << tempColumn - 1 << endl;
    }
    tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath ;
    matrix[tempRow][tempColumn].freeToPass = true;
    ///Down
    //cout << "start  " << tempRow << "      " << tempColumn << endl;
    if (matrix[tempRow + 1][tempColumn].id != lastSpot && matrix[tempRow + 1][tempColumn].value != 0 && matrix[tempRow + 1][tempColumn].freeToPass)
    {
        //cout << "down" << endl;
        //cout << "start  " << tempRow << "      " << tempColumn << endl;
        lastSpot = matrix[tempRow][tempColumn].id;
        matrix[tempRow][tempColumn].freeToPass = false;
        tempRow++;
        path++;
        move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);\
        //cout << "end  " << tempRow - 1 << "      " << tempColumn << endl;
    }
    tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
    matrix[tempRow][tempColumn].freeToPass = true;
    ///Left
    //cout << "start  " << tempRow << "      " << tempColumn << endl;
    if (matrix[tempRow][tempColumn - 1].id != lastSpot && matrix[tempRow][tempColumn - 1].value != 0 && matrix[tempRow][tempColumn - 1].freeToPass)
    {
        //cout << "left" << endl;
        //cout << "start  " << tempRow << "      " << tempColumn << endl;
        lastSpot = matrix[tempRow][tempColumn].id;
        matrix[tempRow][tempColumn].freeToPass = false;
        tempColumn--;
        path++;
        move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
        //cout << "end  " << tempRow << "      " << tempColumn + 1 << endl;
    }
    tempRow = xTempRow , tempColumn = xTempColumn , lastSpot = xLastSpot , path = xPath;
    matrix[tempRow][tempColumn].freeToPass = true;
}
void getSmallestPathToDestination(vector< vector<cell> > matrix , int startRow , int startColumn , int endRow , int endColumn , int row , int column , int plus , int minus)
{
    int path = 0;
    int tempRow = startRow , tempColumn = startColumn;
    int lastSpot = matrix[tempRow][tempColumn].id;
    vector <int> pathCollection;
    move(matrix , tempRow ,tempColumn , endRow , endColumn , lastSpot ,path , row , column , pathCollection);
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
