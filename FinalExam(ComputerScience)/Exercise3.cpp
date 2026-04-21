#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int convertToMinutes(string timeInput) {
    return string(timeInput.substr(0, 2)) * 60 + stoi(timeInput.substr(3));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string timeInput; cin >> timeInput;
    int currentTime = convertToMinutes(timeInput);

    int numberOfFlights; cin >> numberOfFlights;
    string bestFlight = "NULL";
    int totalFlightTime = 86700, totalTransferTime = 86699, bestDepartureTime = 0;

    while (numberOfFlights--) {
        string flightName; cin >> flightName;
        cin >> timeInput;
        int departureTime = convertToMinutes(timeInput);

        int flightDuration, checkinTime, transferTime;
        cin >> flightDuration >> checkinTime >> transferTime;

        if (departureTime + flightDuration + transferTime <= currentTime) {
            if (totalFlightTime >= flightDuration + transferTime + checkinTime) {
                totalFlightTime = flightDuration + transferTime + checkinTime;
                totalTransferTime = departureTime - checkinTime;
                bestFlight = flightName;
                bestDepartureTime = departureTime;
            }
        }
    }

    if (bestFlight != "NULL") {
        cout << bestFlight << '\n';
        int hh = totalTransferTime / 60, mm = totalTransferTime % 60;
        if (hh < 10) cout << '0' << hh << ':';
        else cout << hh << ':';
        if (mm < 10) cout << '0' << mm;
        else cout << mm;
    }
    else {
        cout << "DU IDOL KHONG THANH CONG";
    }

    return 0;
}
