#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


void PrintMatr(int N, const vector<int>& matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
            cout << matrix[i * N + j] << "\t"; 
        }
        cout << endl;
    }
}

void FillMatrix(int N, vector<int>& matrix) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i * N + j] = (rand()%201) - 100;
        }
    }

}


void StandartMultiply(int N, const vector<int>& A, const vector<int>& B, vector<int>& C) {
    for (int i = 0; i < N; i++) {
        int iN = i * N;
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {

                sum += A[iN + k] * B[k * N + j];
            }
            C[iN + j] = sum;
        }
    }
}


void BlockMultiply(int N, int r, const vector<int>& A, const vector<int>& B, vector<int>& C) {
    for (int i = 0; i < N * N; i++) {
        C[i] = 0;
    }
    for (int I = 0; I < N; I += r) {
        for (int J = 0; J < N; J += r) {
            for (int K = 0; K < N; K += r) {

                for (int i = I; i < I + r; i++) {
                    int iN = i * N;
                    for (int j = J; j < J + r; j++) {

                        int sum = 0;
                       
                        for (int k = K; k < K + r; k++) {
                            sum += A[iN + k] * B[k * N + j];
                        }
                         
                        C[iN + j] += sum;
                    }
                }
            }
        }
    }
}
int main() {
    clock_t start, finish;
    double duration;
    int N, r;
    cout << "Enter matrix size N and r: ";
    cin >> N >> r;

    
    vector<int> A(N*N, 0);
    vector<int> B(N * N, 0);
    vector<int> C(N * N, 0);
    
    FillMatrix(N, A);
    FillMatrix(N, B);


    //PrintMatr(N,A);

    start = clock();
    StandartMultiply(N, A, B, C);
    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "Standart algorythm: " << duration << " sec." << endl;

    start = clock();
    BlockMultiply(N, r, A, B, C);
    finish = clock();
    double time_block = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "Block algorythm: " << time_block << " sec." << endl;

    
    
	
}