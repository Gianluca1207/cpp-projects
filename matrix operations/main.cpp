#include <iostream>
#include <vector>
#include <string>
#include <cctype>

// Function to input a matrix from the user
void inputMatrix (std::vector<std::vector<int>>& matrix, int rows, int cols) {
    for (int i=0; i<rows ; i++) {
        for (int j=0; j<cols; j++) {
            int element;
            std::cout << "Enter element at index " << i << " - " << j << " : "; //to display the index, we only have to write i and j, and not matrix[i] and matrix[j] !
            std::cin >> element;
            matrix[i][j] = element;     //In this approach, there is no temporary row vector. Elements are directly assigned to the matrix using matrix[i][j] = element.
        }
    }
}

/* This is the other approach using Temporary Row Vector:

void inputMatrix(std::vector<std::vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        std::vector<int> row;  // Create a new row vector for each iteration
        for (int j = 0; j < cols; ++j) {
            int element;
            std::cout << "Enter element at index " << i << " - " << j << " : ";
            std::cin >> element;
            row.push_back(element);  // Add the element to the row vector
        }
        matrix.push_back(row);  // Add the row vector to the matrix
    }
} */

// Function to add two matrices
std::vector<std::vector<int>> addMatrices (std::vector<std::vector<int>>& A, std::vector<std::vector<int>> B) {   //remember the & !!
    // Get the dimensions (rows and columns) of matrix A
    int rows = A.size();
    int cols = A[0].size() ;

    // Create a new matrix C to store the addition result with the same dimensions as A
    std::vector<std::vector<int>> C(rows, std::vector<int>(cols));    // correct way to initialize a vector of vectors with a specified size  

    // Loop over each element of the matrices A and B
    for (int i=0; i<rows; i++) {
        for (int j=0 ; j<cols ; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

// Function to display a matrix
void displayMatrix (std::vector<std::vector<int>>& matrix) {
    for (int i=0; i<matrix.size() ; i++) {
        std::cout <<"\n";
        for(int j=0; j<matrix[0].size() ; j++) {
            std::cout << matrix[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

// Function to subtract two matrices
std::vector<std::vector<int>> subtractMatrices (std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) {   //remember the & !!
    // Get the dimensions (rows and columns) of matrix A
    int rows = A.size();
    int cols = A[0].size() ;

    // Create a new matrix C to store the addition result with the same dimensions as A
    std::vector<std::vector<int>> C(rows, std::vector<int>(cols));    // correct way to initialize a vector of vectors with a specified size  

    // Loop over each element of the matrices A and B
    for (int i=0; i<rows; i++) {
        for (int j=0 ; j<cols ; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

// Function to multiply two matrices
std::vector<std::vector<int>> multiplyMatrices (std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) {    //remember the & !!
    // Get the dimensions (rows and columns) of matrix A
    int rowsA = A.size();
    int colsA = A[0].size() ;
                              //we don't need rowsB to perform matrix multiplication
    int colsB = B[0].size();

    // Create a new matrix C to store the multiplication result with rowsA and colsB as dimensions
    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB));    // correct way to initialize a vector of vectors with a specified size  

    // Perform matrix multiplication
    for (int i=0; i<rowsA; i++) {
        for (int j=0 ; j<colsB ; j++) {
            for (int k=0; k<colsA; k++) {
            C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main() {

    int rowsA, rowsB, colsA, colsB;

    // Get dimensions for matrix A
    std::cout << "Enter the number of rows for matrix A: ";
    std::cin >> rowsA;
    std::cout << "Enter the number of columns for matrix A: ";
    std::cin >> colsA;

    // Get dimensions for matrix B
    std::cout << "Enter the number of rows for matrix B: ";
    std::cin >> rowsB;
    std::cout << "Enter the number of columns for matrix B: ";
    std::cin >> colsB;

    // Check if matrices can be added, subtracted
    if (colsA != colsB || rowsA != rowsB) {
        std::cerr << "Matrices cannot be added or subtracted because their dimensions are different.\n";
        return 1;        //// Exit with an error code
    }

    if (colsA != rowsB) {      //In matrix multiplication, the number of columns in the first matrix must be equal to the number of rows in the second matrix
        std::cerr << "Matrices cannot be multiplied because the number of columns in the first matrix is not equal to the number of rows in the second matrix.\n";
        return 1;                
    }

    //initialize matrices using vectors with each element set to 0
    std::vector<std::vector<int>> A (rowsA, std::vector<int>(colsA, 0));  //In this example, the std::vector<int>(cols, 0) part creates a vector of cols elements, each initialized to 0. 
    std::vector<std::vector<int>> B (rowsB, std::vector<int>(colsB,0));
    std::vector<std::vector<int>> C (rowsA, std::vector<int>(colsA, 0));  //same dimensions as matrix A for storing the result of matrix addition
    std::vector<std::vector<int>> D (rowsA, std::vector<int>(colsA, 0));  //same dimensions as matrix A for storing the result of matrix subtraction
    std::vector<std::vector<int>> E (rowsA, std::vector<int>(colsB, 0)); //used to store the result of matrix multiplication. The number of columns in E is determined 
                                                                          // by the number of columns in matrix B (colsB)

    std::cout << "Enter elements for matrix A:\n";
    inputMatrix (A, rowsA, colsA);

    std::cout << "Enter elements for matrix B:\n";
    inputMatrix (B, rowsB, colsB);

    C = addMatrices(A, B);
    std::cout << "Matrix C (A + B):\n";
    displayMatrix(C);

    D = subtractMatrices(A, B);
    std::cout << "Matrix D (A - B):\n";
    displayMatrix(D);

    E = multiplyMatrices(A, B);
    std::cout << "Matrix E (A * B):\n";
    displayMatrix(E);


    return 0;
}