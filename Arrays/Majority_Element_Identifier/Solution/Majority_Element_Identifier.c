int majorityElement(int *arr, int n)
{
    int candidate = 0;
    int count = 0;

    // Phase 1: Find a candidate
    for (int i = 0; i < n; i++) {

        if (count == 0)
            candidate = arr[i];

        if (arr[i] == candidate)
            count++;
        else
            count--;
    }

    // Phase 2: Verify the candidate
    count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }

    if (count > n / 2)
        return candidate;

    return -1;  // No majority element
}