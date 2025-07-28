class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int write_idx = 0; // This pointer will track the position to write non-val elements

        for (int read_idx = 0; read_idx < nums.size(); ++read_idx) {
            // If the current element is not equal to val,
            // we want to keep it and move it to the front of the array.
            if (nums[read_idx] != val) {
                nums[write_idx] = nums[read_idx];
                write_idx++; // Move the write pointer forward
            }
            // If nums[read_idx] == val, we simply skip it and don't increment write_idx,
            // effectively "removing" it by overwriting it later with a valid element.
        }

        // write_idx now represents the number of elements that are not equal to val,
        // and these elements are correctly placed at the beginning of the array.
        return write_idx;
    }
};