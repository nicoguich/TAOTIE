void dessine_robot() {
  background(255);
  fill(255);
  stroke(1);
  pushMatrix();
  translate(50, -50);
  /// rectangle central
  fill(255);
  rect(350, 150, 100, 100);

  textSize(8);
  //qtr av
  fill(qtr_color[0]);
  text("q0", 420, 160);
  text(qtr_value[0], 420, 170);
  fill(qtr_color[1]);
  text("q1", 400, 160);
  text(qtr_value[1], 400, 170);
  fill(qtr_color[2]);
  text("q2", 380, 160);
  text(qtr_value[2], 380, 170);
  //qtr droite
  fill(qtr_color[3]);
  text("q3", 415, 215);
  text(qtr_value[3], 430, 215);
  fill(qtr_color[4]);
  text("q4", 415, 200);
  text(qtr_value[4], 430, 200);
  fill(qtr_color[5]);
  text("q5", 415, 185);
  text(qtr_value[5], 430, 185);
  //qtr ar
  fill(qtr_color[8]);
  text("q8", 420, 230);
  text(qtr_value[8], 420, 240);
  fill(qtr_color[7]);
  text("q7", 400, 230);
  text(qtr_value[7], 400, 240);
  fill(qtr_color[6]);
  text("q6", 380, 230);
  text(qtr_value[6], 380, 240);
  //qtr gauche
  fill(qtr_color[9]);
  text("q9", 352, 215);
  text(qtr_value[9], 370, 215);
  fill(qtr_color[10]);
  text("q10", 352, 200);
  text(qtr_value[10], 370, 200);
  fill(qtr_color[11]);
  text("q11", 352, 185);
  text(qtr_value[11], 370, 185);



  textSize(12);
  ///rectangle av
  //fill(255);
 // rect(380, 50, 40, 100);
  fill(sonar_color[0]);
  text("s0:"+sonar_value[0], 380, 140);

  ///rectangle gauche
 // fill(255);
 // rect(250, 180, 100, 40);
   fill(sonar_color[3]);
  text("s3:"+sonar_value[3], 300, 200);

  ///rectangle droite
//  fill(255);
 // rect(450, 180, 100, 40);
   fill(sonar_color[1]);
  text("s1:"+sonar_value[1], 460, 200);

  ///rectangle ar
//  fill(255);
//  rect(380, 250, 40, 100);
   fill(sonar_color[2]);
  text("s2:"+sonar_value[2], 380, 280);
  
  
   /*image(img_sel,475,275);
   if (ligne_ok){
     text(type_ligne,570,300);}
        if (T_ok){
     text(type_T,570,300);}
  */
//  text("X: "+coordX+"  Y: "+coordY+ "  angle: "+ angle,300,400);
//  text(etape_croisement,570,300);
  popMatrix();

 
 fill(0);
 text ("show",600,45);
  text ("get",650,45);
  text("send limit",720,45);
  text(str(limit_qtr),675,70);
   text(str(limit_sonar),675,110);
    text(str(limit_batterie),675,150);
  
  
}
