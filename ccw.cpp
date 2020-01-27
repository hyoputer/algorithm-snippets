ll ccw(pl p1, pl p2, pl p3) {
    ll temp = p1.first*p2.second+p2.first*p3.second+p3.first*p1.second;
    temp = temp - p1.second*p2.first-p2.second*p3.first-p3.second*p1.first;
    if (temp > 0) {
        return 1;
    } else if (temp < 0) {
        return -1;
    } else {
        return 0;
    }
}