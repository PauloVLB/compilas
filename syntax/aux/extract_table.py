from bs4 import BeautifulSoup
import os

# Path to the HTML file
html_file = os.path.join(os.path.dirname(__file__), 'table.html')

# Parse the HTML file
with open(html_file, 'r', encoding='utf-8') as file:
    soup = BeautifulSoup(file, 'html.parser')

# Find the table
table = soup.find('table')

# Initialize the C++ table as a dictionary
cpp_table = {}

# Extract rows and columns
rows = table.find_all('tr')
headers = [header.text.strip() for header in rows[0].find_all('th')[1:]]  # Terminal symbols (columns)

# print(rows[1:])
# exit()

for row in rows[1:]:  # Non-terminal symbols (rows)
    cells = row.find_all('td')
    if len(cells) < 2:  # Skip rows that don't have enough cells
        continue
    non_terminal = cells[0].text.strip()  # First cell is the non-terminal symbol
    for i, cell in enumerate(cells[1:]):  # Remaining cells are terminal symbol mappings
        terminal = headers[i]
        content = cell.text.strip()
        if content:  # If the cell is not empty
            # Split the content into individual symbols
            symbols = content.replace("::=", "").split()
            cpp_table[(non_terminal, terminal)] = symbols

# Generate C++ code
cpp_code = 'std::map<std::pair<std::string, std::string>, std::vector<std::string>> t;\n'
for (non_terminal, terminal), symbols in cpp_table.items():
    cpp_code += f't[{{"{non_terminal}", "{terminal}"}}] = {{"' + '", "'.join(symbols[1:]) + '"};\n'

# Output the generated C++ code
output_file = os.path.join(os.path.dirname(__file__), 'table.cpp')
with open(output_file, 'w', encoding='utf-8') as file:
    file.write(cpp_code)

print(f"C++ table code has been generated and saved to {output_file}")