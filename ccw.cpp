// from https://www.acmicpc.net/blog/view/27
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
//from http://wookje.dance/2019/05/19/boj-2162/
int iscross(pi a, pi b, pi c, pi d) {
    int r1 = ccw(a,b,c)*ccw(a,b,d);
    int r2 = ccw(c,d,a)*ccw(c,d,b);
    if (!r1 && !r2) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return c<=b && a<=d;
    }
    return r1<=0 && r2<=0;
}