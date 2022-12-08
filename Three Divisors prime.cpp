bool primeNum[1000001];

// Create a dynamic array as initial size is unknown
vector<int> primeArray;

// Sieve of Eratosthenes to calculate all prime number till 10^6.
void sieveOfEratosthenes(int N) {
    for (int i=2; i*i<=N; i++) {

        if (primeNum[i]) {
            for (int j=i*i; j<=N; j=j+i) {
                primeNum[j] = 0;
            }
        }
    }

    // Store all prime numbers in an array. (Prime array will contain all prime numbers sorted till 10^6.)
    for (int i=2; i<=N; i++) {

        if (primeNum[i]) {
            primeArray.push_back(i);
        }
    }

}
int solve(long long n) {
    int counter=0;

    // Check till when square of primeArray elements is less than n.
    int index = 0;
    long long int currentNum = primeArray[index] * primeArray[index];

    while (currentNum <= n) {
        // Increase counter as current prime number square is less than n.
        counter++;
        // Increase the index to move to next prime number.
        index++;

        // If index has reached the last element we have read through all our prime numbers. 
        // This should be sufficient to fetch answer for our constraints. 
        if (index==primeArray.size()) {
            break;
        }

        currentNum = (long long)primeArray[index] * (long long)primeArray[index];
    }
    return counter;
}
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Pre computation

        // Initially set all 10^6 numbers as prime.
        memset(primeNum, 1, sizeof(primeNum));

        // Creating an array consisting of only prime numbers.
        sieveOfEratosthenes(1000000);
        vector<int> ans;
        for (auto n : query) {
            ans.push_back(solve(n));
        }

        return ans;
    }
};