# MNXB11-project-template
## About
This folder shows our final project aswell as the instructions on how to regenerate the results.
# Do the following to recreate our results.
## Get started
*CSV Library(commata for project)

After cloning this library, you have to include the library we used for parsing .csv files. We decided to use *commata*, as it offers many possibilites while beeing header-only and thus easy to install.

To install commata, first make sure you are in the root of the repository.
Then, you want to change into the folder external/ and then afterwards /include. To do so, you can just run *cd external/include*. Now, you just need to run *git clone git@github.com:furfurylic/commata.git*. 

*fmt library(not for project, but for C++ homework)

Change into the folder external/ and then afterwards /include and then run *git clone git@github.com:fmtlib/fmt.git*. Make a new directory build inside fmt and change into build directory. Run the configiration process by running *cmake -DCMAKE_INSTALL_PREFIX=/path(path to the installation directory).* Run make install to build and install the library. 

## Data Preparation
Change into the directory /datasets (*cd datasets*) and first extract all the datasets from the tarball, by running *tar zxvf datasets.tgz*. Then run the bash file *./cleandata.sh* and get the file processed_data.csv.

## Data Extraction
Make sure you are in the directory /datasets (*cd datasets* if needed) and compile the c++ file data_extraction.cxx by running "g++ data_extraction.cxx -Werror -Wall -Wextra -o extraction". Now run *./extraction* to get the dataset Extracted_data.csv.

## Data Analysis
Change into the directory MNXB11-project-template and enter the Apptainer. First run make to compile and link the main.cxx file and then run ./main to get the plots.



