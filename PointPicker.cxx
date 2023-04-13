#include <vtkActor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>
#include <vtkPointPicker.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkRendererCollection.h>
#include <vtkSphereSource.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkLineSource.h>
#include <vtkPicker.h>
#include <vtkTextActor.h>
#include <vtkTextWidget.h>
#include <vtkTextProperty.h>
#include <vtkTextRepresentation.h>
#include <vtkNamedColors.h>
#include <vtkActor.h>
#include <QWidget>
#include <vtkCommand.h>
#include <vtkCoordinate.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkTextRepresentation.h>
#include <vtkTextWidget.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vtkTexturedButtonRepresentation2D.h>
#include <vtkPNGReader.h>
#include <vtkButtonWidget.h>
#include <vtkImageData.h>
#include <vtkTexture.h>
#include <vtkImageViewer2.h>
#include <vtkNamedColors.h>
#include <vtkImageCanvasSource2D.h>
#include <vtkImageData.h>
#include <vtkImageDataGeometryFilter.h>
#include <QVTKOpenGLNativeWidget.h>
#include <vtkActor.h>
#include <vtkDataSetMapper.h>
#include <vtkDoubleArray.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkPointData.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>
#include <vtkTubeFilter.h>
#include <QApplication>
#include <QDockWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPointer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>
#include <vtkHexahedron.h>
#include <QTextEdit>
#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkDoubleArray.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkRegularPolygonSource.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyLine.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <cmath>
#include <cstdlib>
#include <random>
#include <QWidget>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <QtCore/QObject>
#include <QtCore/QDebug>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QLineEdit>
#include <QInputDialog>
#include <QComboBox>
#include <QSpinBox>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCellArray.h>
#include <vtkDataSetMapper.h>
#include <vtkHexahedron.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPoints.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkUnstructuredGrid.h>
#include <vtkEventQtSlotConnect.h>
#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolygon.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>


using namespace std;

bool widget = 0;
double picked[3];
double picked2[3] = {};
double x = 0, y = 0, z = 0, z2 = 0, x2 = 0, y2 = 0;


int LineWidth = 1;
char LineColor[100];


vtkNew<vtkPointPicker> pointPicker;

vtkSmartPointer<vtkTextActor> textActor = vtkSmartPointer<vtkTextActor>::New();
vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkLineSource> lineSource = vtkSmartPointer<vtkLineSource>::New();
std::stringstream ss;
vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

// vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
vtkSmartPointer <vtkTextWidget> textWidget = vtkSmartPointer<vtkTextWidget>::New();
string pt;
string pt2;

bool polyL = false;
bool Line = false;
bool regpoly = false;
bool clearPolyLine = false;

int countPolyLinePoints = 0;

vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer <vtkPolyData>::New();
vtkSmartPointer<vtkPolyLine> polyLine = vtkSmartPointer<vtkPolyLine>::New();
vtkSmartPointer<vtkRegularPolygonSource> polygonSource = vtkSmartPointer<vtkRegularPolygonSource>::New();
vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();

/////////////////////////////////////////Functions used by classes////////////////////////
//set the first point of the line
void SetFirstPoint() {

	lineSource->SetPoint1(picked2[0], picked2[1], picked2[2]);
	return;
}

//set the second point of the line
void SetSecondPoint() {

	lineSource->SetPoint2(picked[0], picked[1], picked[2]);
	//lineSource->Modified();
	lineSource->Update();
}

void InsertPolyPoint() {
	points->InsertNextPoint(picked[0], picked[1], picked[2]);
	std::cout << "Picked value of polyline: " << picked[0] << " " << picked[1] << " "
		<< picked[2] << std::endl;

}






bool ReadFile(char name[100]) {
	int i = 0;
	for (i; i < 101; i++) {
		if (name[i] == '\0')
		{
			break;
		}
	}
	name[i] = '.';
	name[i + 1] = 't';
	name[i + 2] = 'x';
	name[i + 3] = 't';
	name[i + 4] = '\0';

	int j = 0;

	while (name[j] != '\0') {

		cout << name[j];
		j++;
	}
	FILE* file;
	fopen_s(&file, name, "r");
	cout << "file to be read  " << file;
	if (file != NULL) {

		fscanf_s(file, "(%lf,%lf,%lf)\n(%lf,%lf,%lf) \n %d \n %s )", &x, &y, &z, &x2, &y2, &z2, &LineWidth, LineColor, sizeof(LineColor));

		printf("x: %lf, y: %lf, z: %lf\n", x, y, z);
		printf("x2: %lf, y2: %lf, z2: %lf\n", x2, y2, z2);
		printf("LineWidth: %d\n", LineWidth);
		printf("LineColor: %s\n", LineColor);
		cout << "picked= " << picked[1] << "picked2= " << picked2[1] << endl;
		//linestream << line;
		//linestream >> x >> y >> z;
		//if (counter ==1) {
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				picked[i] = x2;
				picked2[i] = x;
			}
			if (i == 1) {
				picked[i] = y2;
				picked2[i] = y;
			}
			if (i == 2) {
				picked[i] = z2;
				picked2[i] = z;
			}
		}
		fclose(file);



		// DrawLineOnce(); 
		return true;
	}
}


bool  WriteFile(string name) {

	fstream my_file;
	my_file.open(name, ios::out);
	if (!my_file) {
		cout << "File not created!";
	}
	else {
		cout << "File created successfully!";
		my_file << "(" << picked2[0] << "," << picked2[1] << "," << picked2[2] << ")" << endl << "(" << picked[0] << "," << picked[1] << "," << picked[2] << ")" << endl << LineWidth << endl << LineColor;
		my_file.close();
		cout << LineColor;
	}

	return true;


}

void DrawPoint() {

	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			ss << "x= ";
		}
		if (i == 1) {
			ss << "y= ";
		}
		ss << picked[i] << ", ";
	}
	pt = ss.str();
	ss.str("");



	vtkNew<vtkNamedColors> colors;


	renderWindow->AddRenderer(renderer);
	renderWindowInteractor->SetRenderWindow(renderWindow);


	do {
		vtkSmartPointer <vtkTextWidget> textWidget = vtkSmartPointer<vtkTextWidget>::New();
		widget = 1;


	} while (widget == 0);



	textActor->SetInput(pt.c_str());

	//textActor->SetInput(floatString2.c_str());
   //textActor->SetInput(to_string(floatString));
	textActor->GetTextProperty()->SetColor(colors->GetColor3d("White").GetData());
	vtkSmartPointer<vtkTextRepresentation> textRepresentation = vtkSmartPointer<vtkTextRepresentation>::New();
	// vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	textRepresentation->GetPositionCoordinate()->SetValue(0.15, 0.15);
	textRepresentation->GetPosition2Coordinate()->SetValue(0.6, 0.18);
	textWidget->SetRepresentation(textRepresentation);

	textWidget->SetInteractor(renderWindowInteractor);
	textWidget->SetTextActor(textActor);
	textWidget->SelectableOff();



	textWidget->On();
	renderWindow->Render();

	//renderWindowInteractor->Start();


	return;
}






namespace {

	// Define interaction style
	class MouseInteractorStylePP : public vtkInteractorStyleTrackballCamera
	{
	public:

		static MouseInteractorStylePP* New();
		vtkTypeMacro(MouseInteractorStylePP, vtkInteractorStyleTrackballCamera);

		int flag = 0;

		virtual void OnLeftButtonDown() override
		{
			std::cout << "Picking pixel: " << this->Interactor->GetEventPosition()[0]
				<< " " << this->Interactor->GetEventPosition()[1] << std::endl;


			this->Interactor->GetPicker()->Pick(this->Interactor->GetEventPosition()[0],
				this->Interactor->GetEventPosition()[1],
				0, // always zero.
				this->Interactor->GetRenderWindow()
				->GetRenderers()
				->GetFirstRenderer());


			this->Interactor->GetPicker()->GetPickPosition(picked);

			std::cout << "Picked value: " << picked[0] << " " << picked[1] << " "
				<< picked[2] << std::endl;



			if (Line) {
				flag++;
				if (flag == 1) {


					for (int i = 0; i < 3; i++) {
						picked2[i] = picked[i];
					}
					SetFirstPoint();
					SetSecondPoint();
					DrawPoint();
				}
				if (flag == 2) {

					SetSecondPoint();
					flag = 0;



					std::cout << "Picked value: " << picked[0] << " " << picked[1] << " "
						<< picked[2] << std::endl;
					std::cout << "Picked2 value: " << picked2[0] << " " << picked2[1] << " "
						<< picked2[2] << std::endl;
					DrawPoint();

				}
			}
			else if (polyL) {
				countPolyLinePoints++;

				InsertPolyPoint();
				//polyData->SetPoints(points);
				polyData->Modified();
				mapper->Update();
				this->Interactor->GetRenderWindow()->Render();

				DrawPoint();
				return;


			}
			if (clearPolyLine) {
				points->Delete();
				clearPolyLine = false;
				countPolyLinePoints = 0;
			}

			vtkInteractorStyleTrackballCamera::OnLeftButtonDown();

		}



		// Forward events

	};

	vtkStandardNewMacro(MouseInteractorStylePP);
}


int main(int argc, char* argv[])
{
	vtkNew<vtkNamedColors> colors;
	vtkNew<vtkNamedColors> namedColors;
	QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());

	QApplication app(argc, argv);

	QMainWindow mainWindow;
	mainWindow.resize(1200, 900);
	QDockWidget controlDock;
	// add the buttons to the main window
	QVBoxLayout* layout = new QVBoxLayout();//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// create the buttons
	QPushButton* regPolygon = new QPushButton("Draw polygon");
	QPushButton* buttonLine = new QPushButton("Draw Line");
	QPushButton* buttonPolyLine = new QPushButton("Draw Polyline");
	layout->addWidget(buttonLine);
	layout->addWidget(regPolygon);
	layout->addWidget(buttonPolyLine);
	QWidget* centralWidget = new QWidget();
	centralWidget->setLayout(layout);
	mainWindow.setCentralWidget(centralWidget);
	//////////////////FOR LINE////////////////////
	QWidget layoutContainer;

	QPointer<QVTKOpenGLNativeWidget> vtkRenderWidget = new QVTKOpenGLNativeWidget();
	char read[100];
	QComboBox* comboBox = new QComboBox();
	QString selectedText;
	QSpinBox* spinBox = new QSpinBox();
	QTextEdit* textBox = new QTextEdit();

	///////////////////////////////FOR POLYLINE/////////
	// Create a polydata to store everything in
	 
	
	QObject::connect(regPolygon, &QPushButton::clicked, [&]() {

		Line = false;
		polyL = false;
		regpoly = true;

		// Get the number of vertices from the user
		int nVertices = QInputDialog::getInt(&mainWindow, "Regular Polygon", "Enter the number of vertices:", 3,3);

		// Setup points for the regular polygon
		vtkNew<vtkPoints> points;
		for (int i = 0; i < nVertices; i++) {
			double x = cos(2 * vtkMath::Pi() * i / nVertices);
			double y = sin(2 * vtkMath::Pi() * i / nVertices);
			points->InsertNextPoint(x, y, 0.0);
		}

		// Create the polygon
		vtkNew<vtkPolygon> polygon;
		polygon->GetPointIds()->SetNumberOfIds(nVertices);
		for (int i = 0; i < nVertices; i++) {
			polygon->GetPointIds()->SetId(i, i);
		}

		// Add the polygon to a list of polygons
		vtkNew<vtkCellArray> polygons;
		polygons->InsertNextCell(polygon);

		// Create a PolyData
		vtkNew<vtkPolyData> polygonPolyData;
		polygonPolyData->SetPoints(points);
		polygonPolyData->SetPolys(polygons);

		// Create a mapper and actor
		vtkNew<vtkPolyDataMapper> mapper;
		mapper->SetInputData(polygonPolyData);

		vtkNew<vtkActor> actor;
		actor->SetMapper(mapper);
		actor->GetProperty()->SetColor(colors->GetColor3d("green").GetData());

		// Create a renderer, render window, and interactor
		vtkNew<vtkRenderer> renderer;
		vtkNew<vtkRenderWindow> renderWindow;
		vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
		renderWindowInteractor->SetRenderWindow(renderWindow);

		// Set up the render window and add the actor
		renderWindow->AddRenderer(renderer);
		renderer->AddActor(actor);
		renderer->SetBackground(namedColors->GetColor3d("Silver").GetData());
		renderWindow->SetWindowName("Regular Polygon");
		renderWindow->Render();

		// Set up the interactor and start the event loop
		vtkNew<vtkInteractorStyleTrackballCamera> style;
		renderWindowInteractor->SetInteractorStyle(style);
		renderWindowInteractor->Start();

		});

	//draw normal polygon
	//QObject::connect(regPolygon, &QPushButton::clicked, [&]() {

	//	Line = false;
	//	polyL = false;
	//	regpoly = true;
	//	
	//	/*mainWindow.addDockWidget(Qt::LeftDockWidgetArea, &controlDock);
	//	QLabel controlDockTitle("Control Dock");
	//	controlDockTitle.setMargin(20);
	//	controlDock.setTitleBarWidget(&controlDockTitle);
	//	QPointer<QVBoxLayout> dockLayout = new QVBoxLayout();
	//	layoutContainer.setLayout(dockLayout);
	//	controlDock.setWidget(&layoutContainer);
	//	mainWindow.setCentralWidget(vtkRenderWidget);*/


	//	// Setup four points
	//	vtkNew<vtkPoints> points;
	//	points->InsertNextPoint(0.0, 0.0, 0.0);
	//	points->InsertNextPoint(1.0, 0.0, 0.0);
	//	points->InsertNextPoint(1.0, 1.0, 0.0);
	//	points->InsertNextPoint(0.0, 1.0, 0.0);

	//	//de mesh matlob n7otha
	//	// Create the polygon
	//	vtkNew<vtkPolygon> polygon;
	//	polygon->GetPointIds()->SetNumberOfIds(4); // make a quad
	//	polygon->GetPointIds()->SetId(0, 0);
	//	polygon->GetPointIds()->SetId(1, 1);
	//	polygon->GetPointIds()->SetId(2, 2);
	//	polygon->GetPointIds()->SetId(3, 3);

	//	// Add the polygon to a list of polygons
	//	vtkNew<vtkCellArray> polygons;
	//	polygons->InsertNextCell(polygon);

	//	// Create a PolyData
	//	vtkNew<vtkPolyData> polygonPolyData;
	//	polygonPolyData->SetPoints(points);
	//	polygonPolyData->SetPolys(polygons);

	//	// Create a mapper and actor
	//	//the next line
	//	//vtkNew<vtkPolyDataMapper> mapper;
	//	mapper->SetInputData(polygonPolyData);

	//	//the next line
	//	//vtkNew<vtkActor> actor;

	//	//the next 2 lines were commented
	//	//actor->SetMapper(mapper);
	//	//actor->GetProperty()->SetColor(colors->GetColor3d("Silver").GetData());

	//	// Visualize
	//	//the next two lines
	//	//vtkNew<vtkRenderer> renderer;
	//	//vtkNew<vtkRenderWindow> renderWindow;
	//	//renderWindow->SetWindowName("Polygon");
	//	//renderWindow->AddRenderer(renderer);
	//	//the next line
	//	//vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	//	//renderWindowInteractor->SetRenderWindow(renderWindow);

	//	//renderer->AddActor(actor);
	//	//renderer->SetBackground(colors->GetColor3d("Salmon").GetData());
	//	//renderWindow->Render();
	//	//renderWindowInteractor->Start();



	//	//mapper->SetInputData(polyData);

	//	//vtkNew<vtkActor> actor;
	//	actor->SetMapper(mapper);
	//	actor->GetProperty()->SetColor(colors->GetColor3d("Tomato").GetData());
	//	renderer->SetBackground(namedColors->GetColor3d("siver").GetData());
	//	renderWindow->SetWindowName("regular polygon");
	//	renderWindowInteractor->SetRenderWindow(renderWindow);
	//	renderer->AddActor(actor);
	//	//1  -> the line below
	//	renderWindow->SetInteractor(renderWindowInteractor);
	//	renderWindow->AddRenderer(renderer);
	//	//2  -> the line below
	//	renderWindow->SetInteractor(vtkRenderWidget->interactor());
	//	renderWindow->GetInteractor()->SetPicker(pointPicker);
	//	vtkNew<MouseInteractorStylePP> style;
	//	renderWindow->GetInteractor()->SetInteractorStyle(style);
	//	vtkRenderWidget->setRenderWindow(renderWindow);

	//	renderWindowInteractor->Start();//da ma3rafsh yet3emelo comment wla la2
	//	
	//	// Display the regular polygon
	//	
	//	//3 the 3 lines below
	//	renderWindow->Render();
	//	renderWindow->GetInteractor()->Start();
	//	mainWindow.show();

	//});

	//draw polyline
	QObject::connect(buttonPolyLine, &QPushButton::clicked, [&]() {
		Line = false;
		polyL = true;
		regpoly = false;

		mainWindow.addDockWidget(Qt::LeftDockWidgetArea, &controlDock);

		QLabel controlDockTitle("Control Dock");
		controlDockTitle.setMargin(20);
		controlDock.setTitleBarWidget(&controlDockTitle);

		QPointer<QVBoxLayout> dockLayout = new QVBoxLayout();

		layoutContainer.setLayout(dockLayout);
		controlDock.setWidget(&layoutContainer);


		mainWindow.setCentralWidget(vtkRenderWidget);




		polyLine->GetPointIds()->SetNumberOfIds(countPolyLinePoints);
		for (unsigned int i = 0; i < countPolyLinePoints; i++)
		{
			polyLine->GetPointIds()->SetId(i, i);
		}


		cells->InsertNextCell(polyLine);



		// Add the points to the dataset
		polyData->SetPoints(points);

		// Add the lines to the dataset
		polyData->SetLines(cells);

		// Setup actor and mapper

		mapper->SetInputData(polyData);

		//vtkNew<vtkActor> actor;
		actor->SetMapper(mapper);
		actor->GetProperty()->SetColor(colors->GetColor3d("Tomato").GetData());

		renderer->SetBackground(namedColors->GetColor3d("SlateGray").GetData());
		renderWindow->SetWindowName("PolyLine");

		renderWindowInteractor->SetRenderWindow(renderWindow);
		renderer->AddActor(actor);




		renderWindow->SetInteractor(renderWindowInteractor);


		renderWindow->AddRenderer(renderer);
		renderWindow->SetInteractor(vtkRenderWidget->interactor());

		renderWindow->GetInteractor()->SetPicker(pointPicker);
		vtkNew<MouseInteractorStylePP> style;
		renderWindow->GetInteractor()->SetInteractorStyle(style);



		vtkRenderWidget->setRenderWindow(renderWindow);


		// Display the line
		renderWindow->Render();


		renderWindow->GetInteractor()->Start();


		mainWindow.show();

	});






	// connect the buttons to slots
	QObject::connect(buttonLine, &QPushButton::clicked, [&]() {
		polyL = false;
		Line = true;
		regpoly = false;

		///////////////////////////////////////////////////////////////GUI LINE////////////////////////////////////////////
		mainWindow.addDockWidget(Qt::LeftDockWidgetArea, &controlDock);

		QLabel controlDockTitle("Control Dock");
		controlDockTitle.setMargin(20);
		controlDock.setTitleBarWidget(&controlDockTitle);

		QPointer<QVBoxLayout> dockLayout = new QVBoxLayout();

		layoutContainer.setLayout(dockLayout);
		controlDock.setWidget(&layoutContainer);

		////////////////////////////////////////////////////////////////////END//////////////////////////////////////

		///////////////////////////////////////////////////////////////COMBOBOX COLOUR LINE/////////////////////////////////////////



		comboBox->addItem("Black");
		comboBox->addItem("White");
		comboBox->addItem("Red");
		selectedText = comboBox->currentText();

		dockLayout->addWidget(comboBox);

		/////////////////////////////////////////////////////////////////END///////////////////////////////////////////////////

		////////////////////////////////////////////////////////SPINBOX LINE WIDTH///////////////////////////////////////
		spinBox->setMinimum(0);
		spinBox->setMaximum(100);
		spinBox->setSingleStep(1);
		spinBox->setValue(1);

		dockLayout->addWidget(spinBox);
		///////////////////////////////////////////////////////////////////////////////END/////////////////////////////////

		///////////////////////////////////////////////////////////////////READ WRITE BUTTONS////////////////////////////////////
		QPushButton* pushButton = new QPushButton("Read File");
		QPushButton* pushButton2 = new QPushButton("Write File");
		dockLayout->addWidget(pushButton);
		dockLayout->addWidget(pushButton2);


		mainWindow.setCentralWidget(vtkRenderWidget);


		///////////////////////LINE/////////////////////////////


		mapper->SetInputConnection(lineSource->GetOutputPort());
		mapper->Update();
		actor->GetProperty()->SetColor(colors->GetColor3d(selectedText.toStdString()).GetData());
		/*LineColor = selectedText.toStdString().c_str();
		actor->GetProperty()->SetLineWidth(spinBox->value());*/
		LineWidth = spinBox->value();
		actor->SetMapper(mapper);
		renderer->AddActor(actor);
		renderWindow->AddRenderer(renderer);

		//renderWindow->SetInteractor(renderWindowInteractor);


		/////////////////////////////////////////////////////READ PUSH BUTTON//////////////////////////////////////

		QObject::connect(pushButton, &QPushButton::released, [&]() {

			QString text2 = QInputDialog::getText(nullptr, "Input File Name to be Read", "File Name");
			qDebug() << "Input: " << text2;


			strcpy(read, text2.toStdString().c_str());


			ReadFile(read);
			spinBox->setValue(LineWidth);
			comboBox->setCurrentText(LineColor);
			vtkSmartPointer<vtkLineSource> lineSource = vtkSmartPointer<vtkLineSource>::New();
			actor->GetProperty()->SetLineWidth(LineWidth);
			actor->GetProperty()->SetColor(colors->GetColor3d(LineColor).GetData());
			SetFirstPoint();
			SetSecondPoint();
			lineSource->Update();
			cout << picked[1] << "                         " << picked2[1];
			mapper->Update();

			DrawPoint();





		});

		//////////////////////////////////////////////////////////////// END///////////////////////////////
		char test[100] = { 't','e','s','t' };
		ReadFile(test);

		SetFirstPoint();
		SetSecondPoint();		
		
		////////////////////////////////////////////////////////////////WRITE PUSH BUTTON////////////////////////////////
		QObject::connect(pushButton2, &QPushButton::released, [&]() {
			QString text = QInputDialog::getText(nullptr, "Input File Name to be written", "File Name");
			qDebug() << "Input: " << text;
			string write;
			write = text.toStdString();
			write = write + ".txt";
			WriteFile(write); 
		});

		//////////////////////////////////////////////////////////////////////END/////////////////////////////////////////////

		////////////////////////////////////////////SET READ VALUES (COLOUR AND WIDTH) IN COMBOBOX AND SPINBOX///////////////
		actor->GetProperty()->SetLineWidth(spinBox->value());
		cout << "color  " << selectedText.toStdString();
		cout << "Linewidth  " << spinBox->value();
		actor->GetProperty()->SetColor(colors->GetColor3d(selectedText.toStdString()).GetData());
		//////////////////////////////////////////////////////////END///////////////////////////////////////////////////////////



		renderer->SetBackground(namedColors->GetColor3d("SlateGray").GetData());
		///////////////////////////////////////////////////////////COMBOBOX WIDGET APPLIED/////////////////////////////////

		QObject::connect(comboBox, (&QComboBox::currentIndexChanged), [&]() {


			selectedText = comboBox->currentText();


			// update selectedText with the current selected item
			actor->GetProperty()->SetColor(colors->GetColor3d(selectedText.toStdString()).GetData());
			qstrcpy(LineColor, qPrintable(selectedText));



			renderWindow->Render();
			});
		///////////////////////////////////////////////////////////END//////////////////////////////////////////////
		// 
		//////////////////////////////////////////////////////////////////////SPINBOX WIDGET APPLIED///////////////////////////////////
		QObject::connect(spinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), [&]() {
			actor->GetProperty()->SetLineWidth(spinBox->value());
			LineWidth = spinBox->value();
			renderWindow->Render();
			});
		////////////////////////////////////////////////////////////////////////////END/////////////////////////////


		///////////////////////////////////////////////RENDERING, RENDERER, RENDERWINDOW, INTERACTOR//////////////////
		//Connect renderWindowInteractor in ONLeftClick with current working interactor
		// 
		// 

		renderWindow->SetInteractor(renderWindowInteractor);


		renderWindow->AddRenderer(renderer);
		renderWindow->SetInteractor(vtkRenderWidget->interactor());

		renderWindow->GetInteractor()->SetPicker(pointPicker);
		vtkNew<MouseInteractorStylePP> style;
		renderWindow->GetInteractor()->SetInteractorStyle(style);



		vtkRenderWidget->setRenderWindow(renderWindow);


		// Display the line
		renderWindow->Render();


		renderWindow->GetInteractor()->Start();


		mainWindow.show();
	});

/*
	//vtkNew<vtkNamedColors> colors;

	// Set the background color.
	std::array<unsigned char, 4> bkg{ {51, 77, 102, 255} };
	colors->SetColor("BkgColor", bkg.data());

	// For the hexahedron; setup the coordinates of eight points.
	// The two faces must be in counter clockwise order as viewed from the
	// outside.
	std::vector<std::array<double, 3>> pointCoordinates;
	pointCoordinates.push_back({ {0.0, 0.0, 0.0} }); // Face 1
	pointCoordinates.push_back({ {1.0, 0.0, 0.0} });
	pointCoordinates.push_back({ {1.0, 1.0, 0.0} });
	pointCoordinates.push_back({ {0.0, 1.0, 0.0} });
	pointCoordinates.push_back({ {0.0, 0.0, 1.0} }); // Face 2
	pointCoordinates.push_back({ {1.0, 0.0, 1.0} });
	pointCoordinates.push_back({ {1.0, 1.0, 1.0} });
	pointCoordinates.push_back({ {0.0, 1.0, 1.0} });

	// Create the points.
	vtkNew<vtkPoints> points;

	// Create a hexahedron from the points.
	vtkNew<vtkHexahedron> hex;

	for (auto i = 0; i < pointCoordinates.size(); ++i)
	{
		points->InsertNextPoint(pointCoordinates[i].data());
		hex->GetPointIds()->SetId(i, i);
	}

	// Add the hexahedron to a cell array.
	vtkNew<vtkCellArray> hexs;
	hexs->InsertNextCell(hex);

	// Add the points and hexahedron to an unstructured grid.
	vtkNew<vtkUnstructuredGrid> uGrid;
	uGrid->SetPoints(points);
	uGrid->InsertNextCell(hex->GetCellType(), hex->GetPointIds());

	// Visualize.
	vtkNew<vtkDataSetMapper> mapper;
	mapper->SetInputData(uGrid);

	vtkNew<vtkActor> actor;
	actor->GetProperty()->SetColor(colors->GetColor3d("PeachPuff").GetData());
	actor->SetMapper(mapper);

	vtkNew<vtkRenderer> renderer;
	vtkNew<vtkRenderWindow> renderWindow;
	renderWindow->SetWindowName("Hexahedron");
	renderWindow->AddRenderer(renderer);
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	renderWindowInteractor->SetRenderWindow(renderWindow);

	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("BkgColor").GetData());
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);

	renderWindow->Render();
	//renderWindowInteractor->Start();

	*/
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if (Line) {
	//	mainWindow.addDockWidget(Qt::LeftDockWidgetArea, &controlDock);

	//	QLabel controlDockTitle("Control Dock");
	//	controlDockTitle.setMargin(20);
	//	controlDock.setTitleBarWidget(&controlDockTitle);

	//	QPointer<QVBoxLayout> dockLayout = new QVBoxLayout();
	//	QWidget layoutContainer;
	//	layoutContainer.setLayout(dockLayout);
	//	controlDock.setWidget(&layoutContainer);

	//	//dockLayout->addWidget(static_cast<QWidget(vtkTextWidget)(&QWidget)>(textWidget));
	//	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();


	//	QComboBox* comboBox = new QComboBox();
	//	comboBox->addItem("Black");
	//	comboBox->addItem("White");
	//	comboBox->addItem("Red");
	//	QString selectedText = comboBox->currentText();


	//	dockLayout->addWidget(comboBox);


	//	QSpinBox* spinBox = new QSpinBox();
	//	spinBox->setMinimum(0);
	//	spinBox->setMaximum(100);
	//	spinBox->setSingleStep(1);
	//	spinBox->setValue(1);

	//	dockLayout->addWidget(spinBox);

	//	QPushButton* pushButton = new QPushButton("Read File");
	//	QPushButton* pushButton2 = new QPushButton("Write File");
	//	dockLayout->addWidget(pushButton);
	//	dockLayout->addWidget(pushButton2);


	//	;
	//	QPointer<QVTKOpenGLNativeWidget> vtkRenderWidget =
	//		new QVTKOpenGLNativeWidget();
	//	mainWindow.setCentralWidget(vtkRenderWidget);



	//	mapper->Update();
	//	mapper->SetInputConnection(lineSource->GetOutputPort());
	//	mapper->Update();
	//	renderWindow->AddRenderer(renderer);
	//	renderWindow->SetInteractor(renderWindowInteractor);
	//	actor->SetMapper(mapper);
	//	renderer->AddActor(actor);

	//	QObject::connect(pushButton, &QPushButton::released, [&]() {

	//		QString text2 = QInputDialog::getText(nullptr, "Input File Name to be Read", "File Name");
	//		qDebug() << "Input: " << text2;
	//		char read[100];

	//		qstrcpy(read, qPrintable(text2));


	//		ReadFile(read);
	//		SetFirstPoint();
	//		SetSecondPoint();

	//		mapper->Update();
	//		actor->SetMapper(mapper);
	//		renderer->AddActor(actor);
	//		vtkRenderWidget->update();
	//		renderWindowInteractor->Initialize();
	//		renderWindow->Render();
	//		});


	//	QObject::connect(pushButton2, &QPushButton::released, [&]() {
	//		QString text = QInputDialog::getText(nullptr, "Input File Name to be written", "File Name");
	//		qDebug() << "Input: " << text;
	//		string write;
	//		write = text.toStdString();
	//		write = write + ".txt";
	//		WriteFile(write); });


	//	vtkNew<vtkNamedColors> colors;





	//	vtkNew<vtkNamedColors> namedColors;






	//	actor->GetProperty()->SetLineWidth(spinBox->value());
	//	cout << "color  " << selectedText.toStdString();
	//	cout << "Linewidth  " << spinBox->value();
	//	actor->GetProperty()->SetColor(colors->GetColor3d(selectedText.toStdString()).GetData());
	//	/*for(int i=0;i<101;i++){
	//		string getcolor = actor->GetProperty()->GetColor();
	//	LineColor[i] = )[i];
	//	if (LineColor[i] == NULL) {
	//		break;
	//	}

	//	}*/



	//	renderer->SetBackground(namedColors->GetColor3d("SlateGray").GetData());

	//	QObject::connect(comboBox, (&QComboBox::currentIndexChanged), [&]() {


	//		selectedText = comboBox->currentText(); // update selectedText with the current selected item
	//		actor->GetProperty()->SetColor(colors->GetColor3d(selectedText.toStdString()).GetData());
	//		qstrcpy(LineColor, qPrintable(selectedText));



	//		renderWindow->Render();
	//		});

	//	QObject::connect(spinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), [&]() {
	//		actor->GetProperty()->SetLineWidth(spinBox->value());
	//		LineWidth = spinBox->value();
	//		renderWindow->Render();
	//		});


	//	//Connect renderWindowInteractor in ONLeftClick with current working interactor
	//	renderWindow->SetInteractor(renderWindowInteractor);

	//	mainWindow.setCentralWidget(vtkRenderWidget);

	//	renderWindow->AddRenderer(renderer);
	//	renderWindow->SetInteractor(vtkRenderWidget->interactor());

	//	renderWindow->GetInteractor()->SetPicker(pointPicker);
	//	vtkNew<MouseInteractorStylePP> style;
	//	renderWindow->GetInteractor()->SetInteractorStyle(style);



	//	vtkRenderWidget->setRenderWindow(renderWindow);

	//	//vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	//	//renderWindowInteractor->SetPicker(pointPicker);
	//	//renderWindowInteractor->SetRenderWindow(renderWindow);


	//	//renderWindowInteractor->SetInteractorStyle(style);



	//	// Display the line
	//	renderWindow->Render();


	//	renderWindow->GetInteractor()->Start();
	//}
	mainWindow.show();

	return app.exec();


}


// VTK part
