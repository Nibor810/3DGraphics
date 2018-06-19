#define _USE_MATH_DEFINES
#define NUMBER_OF_TEXTURES 5
#define SKYBOX_MIN 500
#define WINDOW_SIZE_WIDTH 800
#define WINDOW_SIZE_HEIGHT 600
#define PI 3.14159265358979323846f
#include <GL/freeglut.h>
#include <cstdio>
#include <cmath>
#include <iostream>
#include "Scene.h"
#include "GameObject.h"
#include "CubeDrawComponent.h"
#include "ModelComponent.h"
#include "PlaneComponent.h"
#include "MoveComponent.h"
#include "RelativeComponent.h"
#include "TreeComponent.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Skybox.h"


float lastFrameTime = 0;
GLuint textures[NUMBER_OF_TEXTURES];
int width, height;
Skybox skybox;
float speedfactor = 1;

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

GLfloat qaLightPosition[] = { 0, 6, 0, 1 };
void initLighting()
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
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glPushMatrix();
	glPopMatrix();
}

void initSkybox() {
	skybox.load((SKYBOX_MIN / sin(PI / 4)), textures[1]);
}

void display()
{
	glClearColor(0.6f, 0.6f, 1, 1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	//als je wil dat licht met camera mee gaat, moet hij in de init.
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (float)width / height, 0.1, 3000);
	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_LIGHTING);
	glRotatef(camera.rotX, 1, 0, 0);
	glRotatef(camera.rotY, 0, 1, 0);
	glRotatef(camera.rotZ, 0, 0, 1);
	glTranslatef(camera.posX, camera.posZ, camera.posY);

	scene->drawScene();
	skybox.draw(camera.posX, camera.posY, camera.posZ);
	scene->drawHUD();

	glutSwapBuffers();
}

//add all obejct to scene
void initScene() {
	scene = new Scene();

	GameObject* plane = new GameObject();
	PlaneComponent* planeComponent = new PlaneComponent();
	planeComponent->setColor(0, 1, 0);
	planeComponent->setTexture(textures[2]);
	planeComponent->setSize(40);
	plane->drawComponent = planeComponent;
	plane->setPosition(0, -1, 0);
	plane->setRotationAll(0);
	plane->setScaleAll(1);
	plane->setOffset(0, 0, 0);
	plane->setOffsetRotationAll(0);
	scene->addGameObject(plane);

	/*
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
			cube->setOffset(0, 0, 0);
			scene->addGameObject(cube);

		}
	}
	*/

	GameObject* car = new GameObject();
	model_component* model = new model_component("models/honda_jazz.obj", textures[0]);
	car->drawComponent = model;
	car->setPosition(0, -1, 0);
	car->setRotationAll(0);
	car->setOffsetRotationAll(0);
	car->setScaleAll(0.05f);
	MoveComponent* move = new MoveComponent();
	move->setRotationSpeed(0, 30, 0);
	car->addComponent(move);
	car->setOffset(0, 0, 25);
	scene->addGameObject(car);

	GameObject* miniCar = new GameObject();
	miniCar->drawComponent = model;
	miniCar->setPosition(0, 0, 0);
	miniCar->setRotation(0,0,0);
	miniCar->setScaleAll(0.005f);
	miniCar->setOffset(8, 1, 0);
	miniCar->setOffsetRotation(0,90,0);
	RelativeComponent* comp = new RelativeComponent();
	comp->centerObject = car;
	miniCar->addComponent(comp);
	MoveComponent* move2 = new MoveComponent();
	move2->setRotationSpeed(0, 180, 0);
	miniCar->addComponent(move2);
	scene->addGameObject(miniCar);



}

void loadTexture(int id, const char* location) {
	int bpp, height, width;

	stbi_uc* data = stbi_load(location, &width, &height, &bpp, 3);//get data of image

	glBindTexture(GL_TEXTURE_2D, textures[id]);
	glTexImage2D(GL_TEXTURE_2D,
		0,					//level
		GL_RGB,				//internal format
		width,				//width
		height,				//height
		0,					//border
		GL_RGB,				//data format
		GL_UNSIGNED_BYTE,	//data type
		data);				//data
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void initTextures() {
	stbi_set_flip_vertically_on_load(true);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(NUMBER_OF_TEXTURES, textures);
	loadTexture(0, "models/Jazz_diffuse.jpg");
	loadTexture(1, "models/skybox.png");
	loadTexture(2, "models/eigenfloor.png");
	loadTexture(3, "models/wood.jpg");
	loadTexture(4, "models/leaves.png");
}

void initWorld() {
	initTextures();
	initSkybox();
	initScene();
	scene->loadMap("models/TreeMap.png",textures);
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

void faster() {
	speedfactor+=0.05f;
}

void slower() {
	speedfactor-= 0.05f;
}

void idle()
{
	float frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float deltaTime = frameTime - lastFrameTime;
	lastFrameTime = frameTime;
	const float speed = camera.speed;
	if (keys['a']) move(0, deltaTime*speed);
	if (keys['d']) move(180, deltaTime*speed);
	if (keys['w']) move(90, deltaTime*speed);
	if (keys['s']) move(270, deltaTime*speed);
	if (keys[' ']) moveUp(deltaTime*speed);
	if (keys['e']) moveDown(deltaTime*speed);
	if (keys['f']) faster();
	if (keys['v']) slower();


	scene->updateScene(deltaTime* speedfactor);
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
	glutInitWindowSize(WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
	glutInit(&argc, argv);
	glutCreateWindow("3D Graphics Eindopdracht - Robin Hobbel");
	
	//set memory for list that holds key status
	memset(keys, 0, sizeof(keys));
	initLighting();
	initWorld();
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