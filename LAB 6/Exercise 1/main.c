//      Exercise 1.
//      Category: selection problems
//      Transport company
//      An urban transport company tracks the trips made by its vehicles in a log file (text file named log.txt).
//      The file is organized as follows:
//      • in the first line, a positive integer indicating the number of lines that will follow (no more than 1000)
//      • in the next lines, the information about the trips made by the vehicles, one per line with the format:
//      <code_route> <departure> <destination> <date> <time_departure> <time_arrival> <delay>
//      - <code_route>,<departure>,<destination> are strings of 30 characters at most, respectively representing the route code, the departure and the destination of the trip;
//      - <date> is the date of the trip in the format yyyy/mm/dd;
//      - <time_departure>,<time_arrival> are the hh:mm:ss times of departure and arrival of the trip;
//      - <delay> is an integer >=0 representing the delay accumulated during the trip. Assume that the delay
//      never impacts on the date of a trip.
//      Example of file log.txt:
//      6
//      GTT001 Braccini Porta_Nuova 2018/10/10 18:50:00 19:07:25 1
//      GTT001 Braccini Porta_Nuova 2018/12/10 19:50:00 20:06:00 1
//      GTT002 Politecnico XVIII_Dicembre 2018/10/10 10:01:23 10:12:08 4
//      GTT003 Einaudi Cso_Trapani 2018/09/10 14:11:23 14:38:23 2
//      GTT004 Marmolada Sebastopoli 2018/11/10 00:01:02 00:12:00 3
//      GTT002 Politecnico Piazza_Statuto 2018/11/10 23:11:59 23:20:07 0
//      After reading the file and acquiring its content in an appropriate data structure, the C program should
//      provide a menu to the user, to choose one of the following operations:
//      1. list all rides departed within a certain interval of dates
//      2. list all the trips starting from a given departure
//      3. list all the trips with a given destination
//      4. list all trips that reached their destination late, within a given interval of dates
//      5. list the overall delay accumulated by the trips that are identified by a given route code
//      6. terminate the program
//        To select one of the available operations, the user is asked to enter a command from keyboard. A command consists of a specific word, one per each operation (respectively, "date", "departure", "destination", "delay", "tot-delay" or "end"), eventually followed by the additional data required
//        by the operation, all in the same line. For example, "date" should be followed by two dates in the
//      yyyy/mm/dd format, "departure" should be followed by the name of the departure point, etc.
//      To handle the selection from the menu, use a strategy similar to the example reported in slide 73 of C3bProblem solving with arrays. More specifically, you should define a new enum t_command type,
//        including the symbols c_date, c_departure, c_destination, c_delay, c_tot-delay,
//      c_end. Encode each command with the corresponding t_command symbol, so that you can easily
//      handle the menu selection with a switch-case construct.
//      Suggestions:
//      • implement a readCommand function that acquires the first word of a command from keyboard and
//        returns the corresponding t_command value
//      • implement a menuWord function that takes as parameters the data structure where the trips are
//        stored and the number of stored trips and handles with a menu the acquisition of the commands
//        (initial word with corresponding additional information), as well as the call to the appropriate
//        functions implementing the corresponding operations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 150
#define MAX_TRIPS 1000
#define MAX_STRING_LENGTH 31

typedef struct {
    char code_route[MAX_STRING_LENGTH];
    char departure[MAX_STRING_LENGTH];
    char destination[MAX_STRING_LENGTH];
    char date[11]; // Format yyyy/mm/dd
    char time_departure[9]; // Format hh:mm:ss
    char time_arrival[9]; // Format hh:mm:ss
    int delay;
} Trip;

typedef enum {
    c_date, c_departure, c_destination, c_delay, c_tot_delay, c_end, c_invalid
} t_command;

Trip trips[MAX_TRIPS];
int trip_count = 0;

void readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(file, "%d\n", &trip_count);
    for (int i = 0; i < trip_count; i++) {
        fscanf(file, "%s %s %s %s %s %s %d\n",
               trips[i].code_route,
               trips[i].departure,
               trips[i].destination,
               trips[i].date,
               trips[i].time_departure,
               trips[i].time_arrival,
               &trips[i].delay);
    }

    fclose(file);
}

t_command readCommand(char* input) {
    if (strcmp(input, "date") == 0) return c_date;
    if (strcmp(input, "departure") == 0) return c_departure;
    if (strcmp(input, "destination") == 0) return c_destination;
    if (strcmp(input, "delay") == 0) return c_delay;
    if (strcmp(input, "tot-delay") == 0) return c_tot_delay;
    if (strcmp(input, "end") == 0) return c_end;
    return c_invalid;
}

void listRidesByDate(char* start_date, char* end_date) {
    for (int i = 0; i < trip_count; i++) {
        if (strcmp(trips[i].date, start_date) >= 0 && strcmp(trips[i].date, end_date) <= 0) {
            printf("%s %s %s %s %s %s %d\n",
                   trips[i].code_route,
                   trips[i].departure,
                   trips[i].destination,
                   trips[i].date,
                   trips[i].time_departure,
                   trips[i].time_arrival,
                   trips[i].delay);
        }
    }
}

void listRidesByDeparture(char* departure) {
    for (int i = 0; i < trip_count; i++) {
        if (strcmp(trips[i].departure, departure) == 0) {
            printf("%s %s %s %s %s %s %d\n",
                   trips[i].code_route,
                   trips[i].departure,
                   trips[i].destination,
                   trips[i].date,
                   trips[i].time_departure,
                   trips[i].time_arrival,
                   trips[i].delay);
        }
    }
}

void listRidesByDestination(char* destination) {
    for (int i = 0; i < trip_count; i++) {
        if (strcmp(trips[i].destination, destination) == 0) {
            printf("%s %s %s %s %s %s %d\n",
                   trips[i].code_route,
                   trips[i].departure,
                   trips[i].destination,
                   trips[i].date,
                   trips[i].time_departure,
                   trips[i].time_arrival,
                   trips[i].delay);
        }
    }
}

void listLateRidesByDate(char* start_date, char* end_date) {
    for (int i = 0; i < trip_count; i++) {
        if (strcmp(trips[i].date, start_date) >= 0 && strcmp(trips[i].date, end_date) <= 0
            && trips[i].delay > 0) {
            printf("%s %s %s %s %s %s %d\n",
                   trips[i].code_route,
                   trips[i].departure,
                   trips[i].destination,
                   trips[i].date,
                   trips[i].time_departure,
                   trips[i].time_arrival,
                   trips[i].delay);
        }
    }
}

void totalDelayByRouteCode(char* route_code) {
    int total_delay = 0;
    for (int i = 0; i < trip_count; i++) {
        if (strcmp(trips[i].code_route, route_code) == 0) {
            total_delay += trips[i].delay;
        }
    }
    printf("Total delay for route %s: %d\n", route_code, total_delay);
}

void menuWord() {
    char command[MAX_STRING_LENGTH];
    char param1[MAX_STRING_LENGTH];
    char param2[MAX_STRING_LENGTH];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        t_command cmd = readCommand(command);

        switch (cmd) {
            case c_date:
                scanf("%s %s", param1, param2);
                listRidesByDate(param1, param2);
                break;
            case c_departure:
                scanf("%s", param1);
                listRidesByDeparture(param1);
                break;
            case c_destination:
                scanf("%s", param1);
                listRidesByDestination(param1);
                break;
            case c_delay:
                scanf("%s %s", param1, param2);
                listLateRidesByDate(param1, param2);
                break;
            case c_tot_delay:
                scanf("%s", param1);
                totalDelayByRouteCode(param1);
                break;
            case c_end:
                return;
            default:
                printf("Invalid command.\n");
                break;
        }
    }
}

int main() {
    readFile("transport.txt");
    menuWord();
    return 0;
}
