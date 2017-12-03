# Standard & Average Deviation Calculator
A program that displays a formatted table showing the rainfall for each of the previous 12 months<br />
as well as how much above or below average the rainfall was for each month.

## Setup
1. Download and install [Git](https://git-scm.com/downloads), if you don't already have it.

2. Open terminal and run the git clone command:

   ```
   $ git clone https://github.com/cramaechi/monthly-rainfall-table.git
   ```
    or [download as ZIP](https://github.com/cramaechi/monthly-rainfall-table/archive/master.zip).

3. Go to the project folder:

   ```
   $ cd monthly-rainfall-table
   ```

4. Compile:

   ```
   $ make
   ```
   
## Usage
Run:

```
$ ./rainfall_table
```

Sample Output:
```
Enter average monthly rainfall figures for each month (enter -1 when finished):
48.32 51.34 34.30 53.40 42.3 51.88 35.82 49.34 57.3 49.8 55.38 34.3 -1

What is the current month? 12

Enter actual monthly rainfall figures for each month (enter -1 when finished):
40.83 39.34 52.22 45.83 53.95 42.44 38.83 48.84 55.4 43.82 41.4 48.4 -1



                       Monthly Rainfall Figure Table                                                                  
                                                                                                                      
                       _____________________________                                                                  
                                                                                                                      
        December         January        February           March                                                      
            40.8            39.3            52.2            45.8                                                      
  7.5 blw average. 12.0 blw average. 17.9 abv average.  7.6 blw average.                                              
                                                                                                                      
           April             May            June            July                                                      
            54.0            42.4            38.8            48.8                                                      
 11.7 abv average.  9.4 blw average.  3.0 abv average.  0.5 blw average.                                              
                                                                                                                      
          August       September         October        November                                                      
            55.4            43.8            41.4            48.4                                                      
  1.9 blw average.  6.0 blw average. 14.0 blw average. 14.1 abv average.

```
