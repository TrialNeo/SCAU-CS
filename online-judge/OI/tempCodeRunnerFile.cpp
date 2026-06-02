
void solve(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    while (next_permutation(arr.begin(), arr.end())) {
        if (check(arr)) {
            traversal(arr);
        }
    }
}
