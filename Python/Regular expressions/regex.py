import re

def read_file(file_name):
    try:
        with open(file_name, 'r') as file:
            return file.read()
    except FileNotFoundError:
        print(f"The file '{file_name}' was not found. Please make sure the file exists in the specified location.")
        exit()

def find_matches(data, pattern):
    return re.findall(pattern, data)

def main():
    # Open the text file
    file_name = "random_text.txt"
    data = read_file(file_name)

    
    # Prompt the user to enter the regular expression pattern
    pattern = input("Enter the regular expression pattern to search for: ")

    # Use the find_matches function to find all occurrences of the pattern in the text
    matches = find_matches(data, pattern)

    # Print the matches
    if matches:
        print("Matches found:")
        for match in matches:
            print(match)
    else:
        print("No matches found for the given pattern.")

if __name__ == "__main__":
    main()
