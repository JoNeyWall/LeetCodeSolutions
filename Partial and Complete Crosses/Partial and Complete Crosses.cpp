using namespace std;
#include <vector>
#include <iostream>

// Forward Declarations
int CrossCount(vector<vector<int>> matrix);
void PrintMatrix(vector<vector<int>> matrix);
vector<vector<vector<int>>> SetMatrices();
tuple<vector<int>, vector<tuple<int, int, int>>> ScanRows(int numRows, int numColumns, vector<vector<int>> matrix);
tuple<vector<int>, vector<tuple<int, int, int>>> ScanColumns(int numRows, int numColumns, vector<vector<int>> matrix);

// Main
int main()
{
  vector<vector<vector<int>>> matrices = SetMatrices();

  for (int i = 0; i < matrices.size(); i++)
  {
    cout << endl;
    cout << "The following matrix: ";
    PrintMatrix(matrices[i]);
    cout << "Has a cross count of: " << CrossCount(matrices[i]);
  }

  return 0;
}

// Scans rows for partial and complete rows
tuple<vector<int>, vector<tuple<int, int, int>>> ScanRows(int numRows, int numColumns, vector<vector<int>> matrix)
{
  vector<int> completeRows;
  vector<tuple<int, int, int>> partialRows;

  for (int i = 0; i < numRows; i++)
  {
    bool validRow = true;
    int val1 = -1;
    int val2 = -1;
    int val1Count = 0;
    int val2Count = 0;

    for (int j = 0; j < numColumns; j++)
    {
      int currentVal = matrix[i][j];

      if (val1 == -1)
      {
        val1 = currentVal;
        val1Count += 1;
        continue;
      }

      if (val1 != currentVal && val2 == -1)
      {
        val2 = currentVal;
        val2Count += 1;
        continue;
      }

      if (val1 == currentVal)
      {
        val1Count += 1;
        continue;
      }

      if (val2 == currentVal)
      {
        val2Count += 1;
        continue;
      }

      // Reaching this point means there are 3 unique values
      validRow = false;
      break;
    }

    if (!validRow || (val1Count > 1 && val2Count > 1))
    {
      // Don't add a cross that doesn't make sense.
      continue;
    }

    if (val2 == -1)
    {
      completeRows.push_back(val1);
      continue;
    }

    if (val1Count > val2Count)
    {
      tuple<int, int, int> partialRow = tuple(val1, val2, i);
      partialRows.push_back(partialRow);
      continue;
    }

    tuple<int, int, int> partialRow = tuple(val2, val1, i);
    partialRows.push_back(partialRow);
    continue;
  }

  return tuple(completeRows, partialRows);
}

// Scans rows for partial and complete rows
tuple<vector<int>, vector<tuple<int, int, int>>> ScanColumns(int numRows, int numColumns, vector<vector<int>> matrix)
{
  vector<int> completeColumns;
  vector<tuple<int, int, int>> partialColumns;

  for (int i = 0; i < numColumns; i++)
  {
    bool validColumn = true;
    int val1 = -1;
    int val2 = -1;
    int val1Count = 0;
    int val2Count = 0;
    int val2Position = -1;

    for (int j = 0; j < numRows; j++)
    {
      int currentVal = matrix[j][i];

      if (val1 == -1)
      {
        val1 = currentVal;
        val1Count += 1;
        continue;
      }

      if (val1 != currentVal && val2 == -1)
      {
        val2 = currentVal;
        val2Count += 1;
        val2Position = j;
        continue;
      }

      if (val1 == currentVal)
      {
        val1Count += 1;
        continue;
      }

      if (val2 == currentVal)
      {
        val2Count += 1;
        continue;
      }

      // Reaching this point means there are 3 unique values
      validColumn = false;
      break;
    }

    if (!validColumn || (val1Count > 1 && val2Count > 1))
    {
      // Don't add a cross that doesn't make sense.
      continue;
    }

    if (val2 == -1)
    {
      completeColumns.push_back(val1);
      continue;
    }

    if (val1Count > val2Count)
    {
      tuple<int, int, int> partialRow = tuple(val1, val2, val2Position);
      partialColumns.push_back(partialRow);
      continue;
    }

    tuple<int, int, int> partialRow = tuple(val2, val1, 0);
    partialColumns.push_back(partialRow);
    continue;
  }

  return tuple(completeColumns, partialColumns);
}

// Finds the number of partial crosses within the given matrix
int CrossCount(vector<vector<int>> matrix)
{
  int numRows = matrix.size();
  if (numRows == 0)
  {
    return 0;
  }

  int numColumns = matrix[0].size();
  if (numColumns == 0)
  {
    return 0;
  }

  vector<int> completeRows;
  vector<int> completeColumns;
  vector<tuple<int, int, int>> partialRows;
  vector<tuple<int, int, int>> partialColumns;

  tie(completeRows, partialRows) = ScanRows(numRows, numColumns, matrix);
  tie(completeColumns, partialColumns) = ScanColumns(numRows, numColumns, matrix);

  int result = 0;

  for (int i = 0; i < completeRows.size(); i++)
  {
    for (int j = 0; j < completeColumns.size(); j++)
    {
      if (completeRows[i] == completeRows[j])
      {
        result += 1;
      }
    }
  }

  for (int i = 0; i < partialRows.size(); i++)
  {
    for (int j = 0; j < partialColumns.size(); j++)
    {
      if (partialRows[i] == partialColumns[j])
      {
        result += 1;
      }
    }
  }

  return result;
}

// Simple setup function
vector<vector<vector<int>>> SetMatrices()
{
  vector<vector<vector<int>>> matrices;
  // Matrix 1
  vector<vector<int>> matrix1 = {
      {1, 1, 1, 1, 1},
      {0, 1, 0, 1, 0},
      {1, 1, 1, 1, 1},
      {1, 0, 1, 1, 1},
      {0, 1, 1, 1, 1}};
  matrices.push_back(matrix1);

  // Matrix 2
  vector<vector<int>> matrix2 = {
      {1, 1, 1, 1, 1, 1},
      {0, 0, 0, 1, 0, 1},
      {1, 0, 0, 1, 0, 1},
      {1, 1, 1, 1, 1, 1},
      {1, 0, 0, 1, 0, 1},
      {1, 0, 0, 1, 0, 1},
  };
  matrices.push_back(matrix2);

  // Matrix 3
  vector<vector<int>> matrix3 = {
      {1, 1, 1, 2, 1, 1},
      {0, 5, 0, 1, 0, 1},
      {1, 0, 0, 1, 4, 1},
      {1, 1, 1, 1, 1, 1},
      {1, 0, 3, 1, 0, 1},
      {1, 0, 0, 1, 0, 1},
  };
  matrices.push_back(matrix3);

  for (int i = 0; i < 10; i++)
  {
    vector<vector<int>> randMatrix = {
        {(rand() % 2), (rand() % 2), (rand() % 2), (rand() % 2)},
        {(rand() % 2), (rand() % 2), (rand() % 2), (rand() % 2)},
        {(rand() % 2), (rand() % 2), (rand() % 2), (rand() % 2)},
        {(rand() % 2), (rand() % 2), (rand() % 2), (rand() % 2)},
    };
    matrices.push_back(randMatrix);
  }

  return matrices;
}

// Prints a matrix in a readable way
void PrintMatrix(vector<vector<int>> matrix)
{
  cout << endl;
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[i].size(); j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}