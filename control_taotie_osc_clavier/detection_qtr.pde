void detection_qtr() {


  for (int x=0; x< qtr_value.length; x++) {

    if (qtr_value[x]==1) {
      qtr_color[x]=color(255, 0, 0);

    } else {
      qtr_color[x]=color(0, 0, 0);

    }
  }

}
