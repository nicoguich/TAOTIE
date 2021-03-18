void F_go_on() {



  if (on_ligneH == true) {

    if ((stepX == 1) || (stepX == -1)) {


      if (int(stepY) > 0) {

        dir_change = 12;

      }
      if (stepY < 0) {

        dir_change = 17;
      }


    }

  }

  if (on_ligneV == true) {

    if ((stepY == 1) || (stepY == -1)) {


      if (int(stepX) > 0) {

        dir_change = 15;

      }
      if (int(stepX) < 0) {

        dir_change = 14;
      }


    }
  }




}
