package com.company;

public class Location {
    double lat;
    double lon;

    public Location(double _lat, double _lon) {
        lat = _lat;
        lon = _lon;
    }

    @Override
    public String toString() {
        return "lat: " + lat + " lon: " + lon;
    }
}