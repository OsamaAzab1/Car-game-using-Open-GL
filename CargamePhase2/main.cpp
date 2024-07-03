    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <iostream>
    #include <GL/glut.h>
    #include <ctime>
    #define carNumber 4
    #define lanePoints 11

    using namespace std;

    struct car {
        int opositCarSide;
        float opositCary;
        int r, g, b;
    } opositCars[carNumber];

    struct laneDivider {
        int x;
        float y;
    } laneDividers[lanePoints];

    int random(int minimum, int maximum) {
        return (rand() % (maximum - minimum)) + minimum;
    }

    int carSide = 0;
    int point = 0;
    int life = 3;
    float speed = 6;
    bool gameOver = false;
    bool showButton = false;
    bool showMenu = true;
    bool showInstructions = false;
    unsigned long long startTime = 0;



    void stringWrite(float x, float y, int font, std::string s, float r, float g, float b) {
        glColor3f(r, g, b);
        glRasterPos2f(x, y);
        for (char c : s) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }

    void laneDividerGenerator() {
        for (int i = 0; i < lanePoints; i++) {
            laneDividers[i].y = 70 * i;
        }
    }

    void drawButton() {
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_QUADS);
        glVertex2f(200, 300);
        glVertex2f(400, 300);
        glVertex2f(400, 350);
        glVertex2f(200, 350);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(260, 325);
        string buttonText = "Play Again";
        for (char c : buttonText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }

    void carGenerate() {
        for (int i = 0; i < carNumber; i++) {
            opositCars[i].opositCarSide = random(0, 3);
            opositCars[i].opositCary = 700 + i * 300;
            opositCars[i].r = random(0, 255);
            opositCars[i].g = random(0, 255);
            opositCars[i].b = random(0, 255);
        }
    }

    void roadSide() {
      glPushMatrix();
        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(0,0);
        glVertex2d(20,0);
        glVertex2d(20,10);
        glVertex2d(0,0);
        glEnd();

        glBegin(GL_POLYGON);
        glPopMatrix();
        glColor3ub(255,255,0);
        glVertex2d(0,0);
        glVertex2d(20,10);
        glVertex2d(20,45);
        glVertex2d(0,35);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(0,35);
        glVertex2d(20,45);
        glVertex2d(20,80);
        glVertex2d(0,70);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(0,70);
        glVertex2d(20,80);
        glVertex2d(20,115);
        glVertex2d(0,105);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(0,105);
        glVertex2d(20,115);
        glVertex2d(20,150);
        glVertex2d(0,140);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(0,140);
        glVertex2d(20,150);
        glVertex2d(20,185);
        glVertex2d(0,175);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(0,175);
        glVertex2d(20,185);
        glVertex2d(20,220);
        glVertex2d(0,210);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(0,220);
        glVertex2d(20,220);
        glVertex2d(20,255);
        glVertex2d(0,245);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(0,245);
        glVertex2d(20,255);
        glVertex2d(20,290);
        glVertex2d(0,280);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(0,280);
        glVertex2d(20,290);
        glVertex2d(20,325);
        glVertex2d(0,315);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(0,315);
        glVertex2d(20,325);
        glVertex2d(20,360);
        glVertex2d(0,350);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(0,350);
        glVertex2d(20,360);
        glVertex2d(20,395);
        glVertex2d(0,385);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(0,385);
        glVertex2d(20,395);
        glVertex2d(20,430);
        glVertex2d(0,420);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(0,420);
        glVertex2d(20,430);
        glVertex2d(20,464);
        glVertex2d(0,455);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(0,455);
        glVertex2d(20,465);
        glVertex2d(20,500);
        glVertex2d(0,490);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(0,490);
        glVertex2d(20,500);
        glVertex2d(20,535);
        glVertex2d(0,525);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(0,525);
        glVertex2d(20,535);
        glVertex2d(20,570);
        glVertex2d(0,560);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(0,560);
        glVertex2d(20,570);
        glVertex2d(20,605);
        glVertex2d(0,595);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(0,595);
        glVertex2d(20,605);
        glVertex2d(20,640);
        glVertex2d(0,630);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(0,630);
        glVertex2d(20,640);
        glVertex2d(20,675);
        glVertex2d(0,665);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(0,665);
        glVertex2d(20,675);
        glVertex2d(20,700);
        glVertex2d(0,690);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(0,690);
        glVertex2d(20,700);
        glVertex2d(20,735);
        glVertex2d(0,725);
        glEnd();
        //right side
        glPushMatrix();
        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(580,0);
        glVertex2d(600,0);
        glVertex2d(600,10);
        glVertex2d(580,0);
        glEnd();

        glBegin(GL_POLYGON);
        glPushMatrix();
        glColor3ub(255,255,0);
        glVertex2d(580,0);
        glVertex2d(600,10);
        glVertex2d(600,45);
        glVertex2d(580,35);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(580,35);
        glVertex2d(600,45);
        glVertex2d(600,80);
        glVertex2d(580,70);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(580,70);
        glVertex2d(600,80);
        glVertex2d(600,115);
        glVertex2d(580,105);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(580,105);
        glVertex2d(600,115);
        glVertex2d(600,150);
        glVertex2d(580,140);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(580,140);
        glVertex2d(600,150);
        glVertex2d(600,185);
        glVertex2d(580,175);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(580,175);
        glVertex2d(600,185);
        glVertex2d(600,220);
        glVertex2d(580,210);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(580,210);
        glVertex2d(600,220);
        glVertex2d(600,255);
        glVertex2d(580,245);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(580,245);
        glVertex2d(600,255);
        glVertex2d(600,290);
        glVertex2d(580,280);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(580,280);
        glVertex2d(600,290);
        glVertex2d(600,325);
        glVertex2d(580,315);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(580,315);
        glVertex2d(600,325);
        glVertex2d(600,360);
        glVertex2d(580,350);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(580,350);
        glVertex2d(600,360);
        glVertex2d(600,395);
        glVertex2d(580,385);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(580,385);
        glVertex2d(600,395);
        glVertex2d(600,430);
        glVertex2d(580,420);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(580,420);
        glVertex2d(600,430);
        glVertex2d(600,465);
        glVertex2d(580,455);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(580,455);
        glVertex2d(600,465);
        glVertex2d(600,500);
        glVertex2d(580,490);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(580,490);
        glVertex2d(600,500);
        glVertex2d(600,535);
        glVertex2d(580,525);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(580,525);
        glVertex2d(600,535);
        glVertex2d(600,570);
        glVertex2d(580,560);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(580,560);
        glVertex2d(600,570);
        glVertex2d(600,605);
        glVertex2d(580,595);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(580,595);
        glVertex2d(600,605);
        glVertex2d(600,640);
        glVertex2d(580,630);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(580,630);
        glVertex2d(600,640);
        glVertex2d(600,675);
        glVertex2d(580,665);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(580,665);
        glVertex2d(600,675);
        glVertex2d(600,700);
        glVertex2d(580,690);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex2d(580,690);
        glVertex2d(600,700);
        glVertex2d(600,735);
        glVertex2d(580,725);
        glEnd();
        glPopMatrix();
    }

    void drawCar() {
     glPushMatrix();
        glTranslatef(200.0 * carSide, 50.0, 0.0);
        glBegin(GL_POLYGON);
        glColor3ub(0, 255, 0);
        glVertex2d(90, 4);
        glVertex2d(75, 10);
        glVertex2d(75, 100);
        glVertex2d(90, 110);
        glVertex2d(110, 110);
        glVertex2d(125, 100);
        glVertex2d(125, 10);
        glVertex2d(110, 4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 153, 0);
        glVertex2d(90, 25);
        glVertex2d(90, 55);
        glVertex2d(110, 55);
        glVertex2d(110, 25);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 153);
        glVertex2d(90, 55);
        glVertex2d(85, 77);
        glVertex2d(114, 77);
        glVertex2d(110, 55);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 153, 0);
        glVertex2d(85, 77);
        glVertex2d(75, 100);
        glVertex2d(90, 110);
        glVertex2d(110, 110);
        glVertex2d(125, 100);
        glVertex2d(114, 77);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 0, 0);
        glVertex2d(116, 80);
        glVertex2d(122, 78);
        glVertex2d(123, 84);
        glVertex2d(117, 82);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 0, 0);
        glVertex2d(83, 80);
        glVertex2d(77, 78);
        glVertex2d(76, 84);
        glVertex2d(82, 82);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2d(75, 100);
        glVertex2d(85, 100);
        glVertex2d(92, 105);
        glVertex2d(90, 110);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2d(125, 100);
        glVertex2d(115, 100);
        glVertex2d(108, 105);
        glVertex2d(110, 110);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2d(125, 65);
        glVertex2d(129, 65);
        glVertex2d(129, 75);
        glVertex2d(125, 75);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2d(125, 28);
        glVertex2d(129, 28);
        glVertex2d(129, 38);
        glVertex2d(125, 38);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2d(71, 28);
        glVertex2d(75, 28);
        glVertex2d(75, 38);
        glVertex2d(71, 38);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 153);
        glVertex2d(90, 25);
        glVertex2d(75, 10);
        glVertex2d(90, 4);
        glVertex2d(110, 4);
        glVertex2d(125, 10);
        glVertex2d(110, 25);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(64, 64, 64);
        glVertex2d(90, 4);
        glVertex2d(85, 11);
        glVertex2d(110, 11);
        glVertex2d(110, 4);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(255, 0, 0);
        glVertex2d(90, 4);
        glVertex2d(85, 11);
        glVertex2d(75, 10);
        glVertex2d(90, 4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 0, 0);
        glVertex2d(110, 4);
        glVertex2d(115, 11);
        glVertex2d(125, 10);
        glVertex2d(110, 4);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 153, 0);
        glVertex2d(75, 10);
        glVertex2d(85, 11);
        glVertex2d(82, 16);
        glVertex2d(75, 10);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 153, 0);
        glVertex2d(125, 10);
        glVertex2d(115, 11);
        glVertex2d(118, 17);
        glVertex2d(125, 10);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 51, 0);
        glVertex2d(77, 17);
        glVertex2d(88, 27);
        glVertex2d(88, 41);
        glVertex2d(77, 41);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 51, 0);
        glVertex2d(77, 43);
        glVertex2d(88, 43);
        glVertex2d(88, 53);
        glVertex2d(77, 70);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 51, 0);
        glVertex2d(112, 27);
        glVertex2d(123, 17);
        glVertex2d(123, 41);
        glVertex2d(112, 41);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 51, 0);
        glVertex2d(112, 43);
        glVertex2d(123, 43);
        glVertex2d(123, 70);
        glVertex2d(112, 53);
        glEnd();

        glPopMatrix();
    }

    void oppositeCar(int i) {
        glPushMatrix();
        glTranslatef(opositCars[i].opositCarSide * 200 + 100, opositCars[i].opositCary -= speed * 1.5, 0.0);
        glRotated(180, 0, 0, 1);
        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2d(-30, -35);
        glVertex2d(-30, -20);
        glVertex2d(30, -20);
        glVertex2d(30, -35);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2d(-30, 10);
        glVertex2d(-30, 25);
        glVertex2d(30, 25);
        glVertex2d(30, 10);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(opositCars[i].r, 255, opositCars[i].b);
        glVertex2d(-25, -40);
        glVertex2d(-25, 30);
        glVertex2d(-15, 40);
        glVertex2d(15, 40);
        glVertex2d(25, 30);
        glVertex2d(25, -40);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, opositCars[i].g, 0);
        glVertex2d(-15, -30);
        glVertex2d(-15, 10);
        glVertex2d(15, 10);
        glVertex2d(15, -30);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 50, 0);
        glVertex2d(-23, -38);
        glVertex2d(-23, -7);
        glVertex2d(23, -7);
        glVertex2d(23, -38);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2d(-15, 11);
        glVertex2d(-23, 24);
        glVertex2d(23, 24);
        glVertex2d(15, 11);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3ub(0, 0, 0);
        glVertex2d(-15, 11);
        glVertex2d(-23, 24);
        glVertex2d(23, 24);
        glVertex2d(15, 11);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2d(-22, -5);
        glVertex2d(-22, 19);
        glVertex2d(-17, 9);
        glVertex2d(-17, -5);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2d(18, -5);
        glVertex2d(18, 10);
        glVertex2d(23, 20);
        glVertex2d(23, -5);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3ub(0, 0, 0);
        glVertex2d(18, -5);
        glVertex2d(18, 10);
        glVertex2d(23, 20);
        glVertex2d(23, -5);
        glEnd();

        glPopMatrix();
    }

    void road() {
        glBegin(GL_QUADS);
        glColor3ub(100, 100, 100);
        glVertex2d(20, 0);
        glVertex2d(20, 700);
        glVertex2d(580, 700);
        glVertex2d(580, 0);
        glEnd();
    }
    void myKeyboardFunc(unsigned char key, int x, int y) {
        switch (key) {
            case 27: // Escape key
                exit(1);
                break;
            case ' ':
                speed = speed ? 0.0 : 6;
                glutPostRedisplay();
                break;
            default:
                break;
        }
    }

    void mySpecialKeyFunc(int key, int x, int y) {
        switch (key) {
            case GLUT_KEY_LEFT:
                if (carSide > 0) carSide--;
                glutPostRedisplay();
                break;
            case GLUT_KEY_RIGHT:
                if (carSide < 2) carSide++;
                glutPostRedisplay();
                break;
        }
    }

    void moveLaneDividers() {
        for (int i = 0; i < lanePoints; i++) {
            laneDividers[i].y -= speed;
            if (laneDividers[i].y < -40) {
                laneDividers[i].y = 700;
            }
        }
    }

    void moveOpositCars() {
        for (int i = 0; i < carNumber; i++) {
            opositCars[i].opositCary -= speed;
            if (opositCars[i].opositCary < -70) {
                opositCars[i].opositCary = random(800, 1600);
                opositCars[i].opositCarSide = random(0, 3);
                opositCars[i].r = random(0, 255);
                opositCars[i].g = random(0, 255);
                opositCars[i].b = random(0, 255);
            }
        }
    }
    void checkCollision() {
        for(int i = 0; i < carNumber; i++) {
            // Check collision with player's car
            if(opositCars[i].opositCarSide == carSide) {
                if(opositCars[i].opositCary < 105 && opositCars[i].opositCary >= 30) {
                    life--;
                    if (life == 0) {
                        gameOver = true;
                        return;
                    }
                    opositCars[i].opositCary = random(800, 1600);
                    opositCars[i].opositCarSide = random(0, 1);
                    opositCars[i].r = random(0, 255);
                    opositCars[i].g = random(0, 255);
                    opositCars[i].b = random(0, 255);
                }
            }
        }
    }


    void laneDevider() {
        static int scoreTimer = 0;
        const int scoreDelay = 50;

        for (int i = 0; i < lanePoints; i++) {
            glPushMatrix();
            glTranslatef(200, laneDividers[i].y, 0);
            glBegin(GL_QUADS);
            glColor3ub(255, 255, 0);
            glVertex2d(0, 0);
            glVertex2d(0, 40);
            glVertex2d(10, 40);
            glVertex2d(10, 0);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(400, laneDividers[i].y, 0);
            glBegin(GL_QUADS);
            glColor3ub(255, 255, 0);
            glVertex2d(0, 0);
            glVertex2d(0, 40);
            glVertex2d(10, 40);
            glVertex2d(10, 0);
            glEnd();
            glPopMatrix();

            laneDividers[i].y -= speed;
            if (laneDividers[i].y < -70) {
                laneDividers[i].y = 700;
            }
        }

        // Increment points when the player's car passes a certain distance
        if (laneDividers[0].y <= 700 - 70 && scoreTimer <= 0) {
            point++;
            scoreTimer = scoreDelay; // Set the delay timer
        }

        // Decrement the score delay timer
        if (scoreTimer > 0) {
            scoreTimer--;
        }
    }
    void drawMainMenu() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        glColor3f(1.0, 1.0, 1.0);
        stringWrite(200, 600, 1, "CAR GAME", 1.0, 1.0, 1.0);

        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_QUADS);
        glVertex2f(200, 400);
        glVertex2f(400, 400);
        glVertex2f(400, 450);
        glVertex2f(200, 450);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(260, 425);
        string startText = "Start Game";
        for (char c : startText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }

        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_QUADS);
        glVertex2f(200, 300);
        glVertex2f(400, 300);
        glVertex2f(400, 350);
        glVertex2f(200, 350);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(260, 325);
        string instructionsText = "Instructions";
        for (char c : instructionsText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }

        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_QUADS);
        glVertex2f(200, 200);
        glVertex2f(400, 200);
        glVertex2f(400, 250);
        glVertex2f(200, 250);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(280, 225);
        string exitText = "Exit Game";
        for (char c : exitText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }

        glFlush();
        glutSwapBuffers();
    }
    void drawInstructions() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        glColor3f(1.0, 1.0, 1.0);
        stringWrite(100, 600, 1, "Instructions", 1.0, 1.0, 1.0);

        glColor3f(1.0, 1.0, 1.0);
        stringWrite(50, 550, 1, "1. Use the left and right arrow keys to move your car between lanes.", 1.0, 1.0, 1.0);
        stringWrite(50, 520, 1, "2. Avoid colliding with the oncoming cars.", 1.0, 1.0, 1.0);
        stringWrite(50, 490, 1, "3. You have 3 lives. Each collision will cost you one life.", 1.0, 1.0, 1.0);
        stringWrite(50, 460, 1, "4. Score points by passing the divider lines.", 1.0, 1.0, 1.0);
        stringWrite(50, 430, 1, "5. Press the space bar to pause or resume the game.", 1.0, 1.0, 1.0);

        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_QUADS);
        glVertex2f(200, 100);
        glVertex2f(400, 100);
        glVertex2f(400, 150);
        glVertex2f(200, 150);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(260, 125);
        string backText = "Back to Menu";
        for (char c : backText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }

        glFlush();
        glutSwapBuffers();
    }



    void renderScene() {
        if (showMenu) {
            drawMainMenu();
        } else if (showInstructions) {
            drawInstructions();
        } else {
            //unsigned long long currentTime = static_cast<unsigned long long>(time(NULL));
            //unsigned long long elapsedTime = currentTime - startTime;
            //stringWrite(10, 50, 1, "Time: " + to_string(elapsedTime) + " seconds", 1.0, 1.0, 1.0);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();
            road();
            roadSide();
            laneDevider();

            for (int i = 0; i < carNumber; i++) {
                oppositeCar(i);
            }

            drawCar();

            stringWrite(10, 10, 1, "Points: " + to_string(point), 1.0, 1.0, 1.0);
            stringWrite(10, 30, 1, "Lives: " + to_string(life), 1.0, 1.0, 1.0);
            if (gameOver) {
                stringWrite(250, 350, 1, "Game Over!", 1.0, 0.0, 0.0);
                glFlush();
                glutSwapBuffers();
                showButton = true;
            }
            if (showButton) {
                drawButton();
            }
            moveLaneDividers();
            checkCollision();
            moveOpositCars();

            glFlush();
            glutSwapBuffers();
        }
    }

    void update(int value) {
        glutPostRedisplay();
        glutTimerFunc(16, update, 0);
    }

void initialize() {
    // Set a clear color that contrasts with the menu items
    glClearColor(0.8, 0.8, 0.8, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 700.0, 0.0);
    glMatrixMode(GL_MODELVIEW);

    laneDividerGenerator();
    carGenerate();
    startTime = static_cast<unsigned long long>(time(NULL));

}

    void handleMouseClick(int button, int state, int x, int y) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (showMenu) {
                if (x >= 200 && x <= 400 && y >= 400 && y <= 450) {
                    showMenu = false;
                    initialize();
                } else if (x >= 200 && x <= 400 && y >= 300 && y <= 350) {
                    showInstructions = true;
                    showMenu = false;
                } else if (x >= 200 && x <= 400 && y >= 200 && y <= 250) {
                    exit(0);
                }
            } else if (showInstructions) {
            if (x >= 200 && x <= 400 && y >= 100 && y <= 150) {
            showInstructions = false;
            showMenu = true;
            }
            } else {
    if (x >= 200 && x <= 400 && y >= 300 && y <= 350) {
    point = 0;
    life = 3;
    speed = 6;
    gameOver = false;
    showButton = false;
    carGenerate();
    }
    }
    }
    }
    void debugInfo() {
        cout << "Debugging Information:" << endl;
        cout << "Car Side: " << carSide << endl;
        cout << "Point: " << point << endl;
        cout << "Life: " << life << endl;
        cout << "Speed: " << speed << endl;
    }

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600, 700);
    glutInitWindowPosition(100, 100);
    int windowHandle = glutCreateWindow("Car Game");
    // Ensure initialize is called before rendering
    initialize();
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(myKeyboardFunc);
    glutSpecialFunc(mySpecialKeyFunc);
    glutMouseFunc(handleMouseClick);
    glutTimerFunc(16, update, 0);
    debugInfo();

    glutMainLoop();
    return 0;
}
