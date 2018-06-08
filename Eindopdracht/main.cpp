#include <GL/freeglut.h>
#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Scene.h"
#include "GameObject.h"
#include "CubeDrawComponent.h"
#include "stb_image.h"

#define STB_IMAGE_IMPLEMENTATION
float lastFrameTime = 0;

int width, height;

//struct to keep camera position
struct Camera
{
	float speed = 3;
	float posX = 0;
	float posY = -4;
	float posZ = 0;
	float rotX = 0;
	float rotY = 0;
	float rotZ = 0;
} camera;

Vector3D lightPosition = Vector3D(0,6,0);

bool keys[255];
Scene* scene;
/*
GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 }; //Black Color
GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 }; //Green Color
GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 }; //White Color
GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 }; //White Color
// Set lighting intensity and color
// Light source position
*/
GLfloat qaLightPosition[] = { 0, 6, 0, 1 };
void init()
{
	GLfloat qaAmbientLight[] = { 0, 0, 0, 1 };
	GLfloat qaDiffuseLight[] = { 1, 1, 1, 1 };
	GLfloat qaSpecularLight[] = { 1, 1, 1, 1 };
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaSpecularLight);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, qaAmbientLight);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glPushMatrix();
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
	glPopMatrix();
}

void updateLight(float deltaTime) 
{

}

void drawSphere(float radius) {
	//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGreen);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGreen);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	//glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);
	glColor3f(0,1,0);
	glutSolidSphere(radius, 25, 25);
}


void display()
{
	glClearColor(0.6f, 0.6f, 1, 1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	//als je wil dat licht met camera mee gaat, moet hij in de init.
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (float)width / height, 0.1, 30);
	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glRotatef(camera.rotX, 1, 0, 0);
	glRotatef(camera.rotY, 0, 1, 0);
	glRotatef(camera.rotZ, 0, 0, 1);
	glTranslatef(camera.posX, camera.posZ, camera.posY);

	glPushMatrix();
	glTranslatef(qaLightPosition[0], qaLightPosition[1], qaLightPosition[2]);
	drawSphere(1);
	glPopMatrix();


	glColor3f(0.1f, 1.0f, 0.2f);
	glBegin(GL_QUADS);
	glVertex3f(-15, -1, -15);
	glVertex3f(15, -1, -15);
	glVertex3f(15, -1, 15);
	glVertex3f(-15, -1, 15);
	glEnd();

	scene->drawScene();

	glutSwapBuffers();
}

void initScene() {
	scene = new Scene();
	
	for (int x = -10; x <= 10; x += 5)
	{
		for (int y = -10; y <= 10; y += 5)
		{
			GameObject* cube = new GameObject();
			CubeDrawComponent* cubeComponent = new CubeDrawComponent();
			cubeComponent->setColor(1, 0, 0);
			cubeComponent->setSize(1);
			cube->drawComponent = cubeComponent;
			cube->setPosition(x, 0, y);
			cube->setRotationAll(0);
			cube->setScaleAll(1);
			scene->addGameObject(cube);
		}
	}
}


void moveUp(float fac)
{
	camera.posZ -= 1 * fac;
}

void moveDown(float fac)
{
	camera.posZ += 1 * fac;
}

void move(float angle, float fac)
{
	camera.posX += (float)cos((camera.rotY + angle) / 180 * M_PI) * fac;
	camera.posY += (float)sin((camera.rotY + angle) / 180 * M_PI) * fac;
}

void idle()
{
	float frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float deltaTime = frameTime - lastFrameTime;
	lastFrameTime = frameTime;
	updateLight(deltaTime);

	const float speed = camera.speed;
	if (keys['a']) move(0, deltaTime*speed);
	if (keys['d']) move(180, deltaTime*speed);
	if (keys['w']) move(90, deltaTime*speed);
	if (keys['s']) move(270, deltaTime*speed);
	if (keys[' ']) moveUp(deltaTime*speed);
	if (keys['e']) moveDown(deltaTime*speed);

	glutPostRedisplay();
}

bool justMovedMouse = false;


//on mouse moved function
void mousePassiveMotion(int x, int y)
{
	int dx = x - width / 2;
	int dy = y - height / 2;
	if ((dx != 0 || dy != 0) && abs(dx) < 400 && abs(dy) < 400 && !justMovedMouse)
	{
		camera.rotY += dx / 10.0f;
		camera.rotX += dy / 10.0f;
	}
	if (!justMovedMouse)
	{
		glutWarpPointer(width / 2, height / 2);
		justMovedMouse = true;
	}
	else
		justMovedMouse = false;
}

//on key press function
void keyboard(unsigned char key, int, int)
{
	if (key == 27)
		exit(0);
	std::cout << key << " pressed";
	keys[key] = true;
}

//on key released function
void keyboardUp(unsigned char key, int, int)
{
	keys[key] = false;
}

int main(int argc, char* argv[])
{
	
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInit(&argc, argv);
	glutCreateWindow("3D Graphics Eindopdracht - Robin Hobbel");
	
	//set memory for list that holds key status
	memset(keys, 0, sizeof(keys));
	init();
	initScene();

	
	
	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutReshapeFunc([](int w, int h) { width = w; height = h; glViewport(0, 0, w, h); });
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutPassiveMotionFunc(mousePassiveMotion);
	
	glutWarpPointer(width / 2, height / 2);

	glutMainLoop();


	return 0;
}