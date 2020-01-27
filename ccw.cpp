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

if(ccw(points[0], points[1], points[2]) == 0)
  {
    if(points[2].first >= min(points[0].first, points[1].first) && points[2].first <= max(points[0].first, points[1].first))
      printf("1\n");
    else
    {
      if(ccw(points[0], points[1], points[3]) == 0 && 
         points[3].first >= min(points[0].first, points[1].first) && points[3].first <= max(points[0].first, points[1].first))
        printf("1\n");
      else
        printf("0\n");
    }
  }
  else if (ccw(points[0], points[1], points[3]) == 0)
  {
    if(points[3].first >= min(points[0].first, points[1].first) && points[3].first <= max(points[0].first, points[1].first))
      printf("1\n");
    else
      printf("0\n");
  }
  else
  {
    if(ccw(points[0], points[1], points[2]) != ccw(points[0], points[1], points[3]) && 
       ccw(points[2], points[3], points[0]) != ccw(points[2], points[3], points[1]))
      printf("1\n");
    else
      printf("0\n");
  }