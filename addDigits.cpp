int addDigits(int num) {
    while (num >= 10) { // Continue until we have a single digit
        int sum = 0;
        std::string numStr = std::to_string(num); // Convert the number to a string

        for (char c : numStr) { // Iterate over each character in the string
            sum += c - '0'; // Convert the character to its integer value and add to the sum
        }

        num = sum; // Update num to the sum of its digits
    }
    return num;
}
