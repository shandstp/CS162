/**
  * @brief Assignment 7 Problem 1
  * @brief Travis Shands
  */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * @brief getData Gets input from keyboard and stores as array
 * @param heights Array into which input is stored
 * @param size Defines length of array
 */
void getData(int heights[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cin >> heights[i];
    }
}

/**
 * @brief getHighestPointBetween evaluates all elevations between two given checkpoints and determines which is highest
 * @param heights array consisting of elevations for each checkpoint
 * @param startMile value of first checkpoint for comparison
 * @param endMile value of second checkpoint for comparison
 * @return returns height of highest checkpoint compared
 */
int getHighestPointBetween(const int heights[], int startMile, int endMile)
{
    int highestPoint = heights[startMile];
    for(int i = startMile; i < endMile; i++)
    {
        if(heights[i] > highestPoint)
        {
            highestPoint = heights[i];
        }
    }
    return highestPoint;
}

/**
 * @brief getAverage calculates the average elevation of all checkpoints
 * @param heights array of elevations to be averaged
 * @param size defines length of array
 * @return returns the average elevation of all checkpoints
 */
double getAverage(const int heights[], int size)
{
    double average = 0;
    for(int i = 0; i < size; i++)
    {
        average = heights[i] + average;
    }
    return average / size;
}

/**
 * @brief getNumPeaks returns number of peaks throughout duration of hike
 * @param height array of elevations during hike
 * @param size defines size of array
 * @return returns number of peaks throughout duration of hike
 */
int getNumPeaks(const int height[], int size)
{
    int peakCount = 0;
    for(int i = 1; i < size - 1; i++)
    {
        if(height [i] > height[i - 1] && height[i] > height[i + 1])
            peakCount++;
    }
    return peakCount;
}

/**
 * @brief getNumSteepSegments return the number of segments that end with a change of more than 1000 feet
 * @param heights height array of elevations during hike
 * @param size defines size of array
 * @return returns the number of segments that end with a change of more than 1000 feet
 */
int getNumSteepSegments(const int heights[], int size)
{
    int hardSegmentCount = 0;
    for(int i = 1; i < size; i++)
    {
        if(abs(heights[i] - heights[i - 1]) > 1000)
            hardSegmentCount++;
    }
    return hardSegmentCount;
}

/**
 * @brief getTotalChange reports the total change in elevation throughout the duration of hike
 * @param heights height array of elevations during hike
 * @param startMile first point to be measured
 * @param endlMile last point to be measured
 * @return returns the total change in elevation throughout the duration of hike
 */
int getTotalChange(const int heights[], int startMile, int endlMile)
{
    int sumOfChanges = 0;
    for(int i = startMile; i < endlMile - 1; i++)
    {
        sumOfChanges = sumOfChanges + abs(heights[i] - heights[i + 1]);
    }
    return sumOfChanges;
}


int main()
{
    const int HIKE_LENGTH = 9;
    int checkpoints[HIKE_LENGTH] = {0};
    cout << fixed << setprecision(2) << "Enter elevations: ";
    getData(checkpoints, HIKE_LENGTH);

    int firstHalfHighest;
    int secondHalfHighest;
    if(HIKE_LENGTH % 2 == 0)
    {
        firstHalfHighest = getHighestPointBetween(checkpoints, 0, HIKE_LENGTH / 2);
        secondHalfHighest = getHighestPointBetween(checkpoints, HIKE_LENGTH / 2, HIKE_LENGTH);
    }
    else
    {
        firstHalfHighest = getHighestPointBetween(checkpoints, 0, HIKE_LENGTH / 2);
        secondHalfHighest = getHighestPointBetween(checkpoints, (HIKE_LENGTH / 2) + 1, HIKE_LENGTH);
    }

    cout << "Highest points:" << endl;
    cout << "   " << "First half: " << firstHalfHighest << endl;
    cout << "   " << "Second half: " << secondHalfHighest << endl;
    cout << "   " << "Overall: " << getHighestPointBetween(checkpoints, 0, HIKE_LENGTH) << endl;

    cout << "Average elevation: " << getAverage(checkpoints, HIKE_LENGTH) << endl;

    cout << "Peaks: " << getNumPeaks(checkpoints, HIKE_LENGTH) << endl;

    cout << "Difficult segments: " << getNumSteepSegments(checkpoints, HIKE_LENGTH) << endl;

    cout << "Elevation change: " << getTotalChange(checkpoints, 0, HIKE_LENGTH) << endl;

    return 0;
}
