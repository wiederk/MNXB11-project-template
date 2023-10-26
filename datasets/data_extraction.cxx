#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

int main() {
    std::string inputFileName = "processed_data.csv"; 
    std::string outputFileName = "Extracted_data.csv"; 

    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

     std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Error: Unable to open output file." << std::endl;
        inputFile.close();
        return 1;
    }

    // Define a map to store daily temperature data for each year
    std::map<std::string, std::vector<double>> dayToDailyTemperatures;

    // Read and process the input file
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        std::string date, time; double temperature;

        // Parse the CSV data
        if (std::getline(lineStream, date, ',') &&
            std::getline(lineStream, time, ',') &&
            lineStream >> temperature) {
            // Combine the date and time to create a unique day identifier
            std::string day = date;

            // Store the temperature in the corresponding day's daily temperature vector
            dayToDailyTemperatures[day].push_back(temperature);
        }
    }

    // Write the daily mean temperatures to the output file
    for (const auto& entry : dayToDailyTemperatures) {
        std::string day = entry.first;
        const std::vector<double>& dailyTemperatures = entry.second;
        double dailyMean = 0.0;
        for (double temp : dailyTemperatures) {
            dailyMean += temp;
        }
        dailyMean /= dailyTemperatures.size();
        // Write the day and daily mean temperature to the output file
        outputFile << day << "," << dailyMean << "\n";
    }


    // Close the input and output files
     inputFile.close();
    outputFile.close();

    std::cout << "Daily mean temperatures have been calculated and saved to " << outputFileName << std::endl;

    return 0;
}
