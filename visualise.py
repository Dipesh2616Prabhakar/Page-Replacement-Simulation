import matplotlib.pyplot as plt

# Read the results file
with open("results.txt", "r") as file:
    data = file.readlines()

# Process data
algorithms = []
faults = []
for line in data:
    algo, fault_count = line.split()
    algorithms.append(algo)
    faults.append(int(fault_count))

# Create a bar chart
fig, ax = plt.subplots()
bars = ax.bar(algorithms, faults, color=['orange', 'violet', 'green'])

plt.xlabel("Page Replacement Algorithms")
plt.ylabel("Total Page Faults")
plt.title("Comparison of Page Replacement Algorithms")
