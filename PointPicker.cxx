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
#include< stdio.h >
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
//#include <vtkEventQtSlotConnect>
using namespace std;
bool widget = 0;
double picked[3];
double picked2[3] = {};
double x = 0, y = 0, z = 0, z2 = 0, x2 = 0, y2 = 0;

//double *xp=&x , *yp = &y, *zp = &z, *x2p = &x2, *y2p = &y2, *z2p = &z2;
int LineWidth = 5;
char LineColor[100] = { 'B','l','a','c','k' };

//LineColor[0]='B';
vtkNew<vtkPointPicker> pointPicker;

vtkSmartPointer<vtkTextActor> textActor = vtkSmartPointer<vtkTextActor>::New();
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
/////////////////////////////////////////Functions used by classes////////////////////////
void SetFirstPoint() {

	lineSource->SetPoint1(picked2[0], picked2[1], picked2[2]);
	return;



}

void SetSecondPoint() {

	lineSource->SetPoint2(picked[0], picked[1], picked[2]);
	//lineSource->Modified();
	lineSource->Update();

}







bool ReadFile(char name[100]) {
	int i = 0;
	for (i; i < 101; i++) {
		if (name[i] == NULL) {
			break;
		}
	}
	name[i] = '.';
	name[i + 1] = 't';
	name[i + 2] = 'x';
	name[i + 3] = 't';

	FILE* file;
	fopen_s(&file, name, "r");
	if (file != NULL) {
		LineColor[100] = {};
		fscanf_s(file, "(%lf,%lf,%lf)\n(%lf,%lf,%lf) \n %d \n %s )", &x, &y, &z, &x2, &y2, &z2, &LineWidth, LineColor, sizeof(LineColor));

		printf("x: %lf, y: %lf, z: %lf\n", x, y, z);
		printf("x2: %lf, y2: %lf, z2: %lf\n", x2, y2, z2);
		printf("LineWidth: %d\n", LineWidth);
		printf("LineColor: %s\n", LineColor);
		cout << "picked= " << picked[1] << "picked2= " << picked2[1];
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
		SetFirstPoint();
		SetSecondPoint();

		lineSource->Update();
		/*DrawLineOnce();*/
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

	renderWindowInteractor->Start();


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


			vtkInteractorStyleTrackballCamera::OnLeftButtonDown();

		}



		// Forward events












	};

	vtkStandardNewMacro(MouseInteractorStylePP);
}


int main(int argc, char* argv[])
{
	QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());

	QApplication app(argc, argv);

	QMainWindow mainWindow;
	mainWindow.resize(1200, 900);

	QDockWidget controlDock;
	mainWindow.addDockWidget(Qt::LeftDockWidgetArea, &controlDock);

	QLabel controlDockTitle("Control Dock");
	controlDockTitle.setMargin(20);
	controlDock.setTitleBarWidget(&controlDockTitle);

	QPointer<QVBoxLayout> dockLayout = new QVBoxLayout();
	QWidget layoutContainer;
	layoutContainer.setLayout(dockLayout);
	controlDock.setWidget(&layoutContainer);

	//dockLayout->addWidget(static_cast<QWidget(vtkTextWidget)(&QWidget)>(textWidget));
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();


	QComboBox* comboBox = new QComboBox();
	comboBox->addItem("Black");
	comboBox->addItem("White");
	comboBox->addItem("Red");
	QString selectedText = comboBox->currentText();


	dockLayout->addWidget(comboBox);


	QSpinBox* spinBox = new QSpinBox();
	spinBox->setMinimum(0);
	spinBox->setMaximum(100);
	spinBox->setSingleStep(1);
	spinBox->setValue(1);

	dockLayout->addWidget(spinBox);

	QPushButton* pushButton = new QPushButton("Read File");
	QPushButton* pushButton2 = new QPushButton("Write File");
	dockLayout->addWidget(pushButton);
	dockLayout->addWidget(pushButton2);


	;
	QPointer<QVTKOpenGLNativeWidget> vtkRenderWidget =
		new QVTKOpenGLNativeWidget();
	mainWindow.setCentralWidget(vtkRenderWidget);


	
	mapper->Update();
	mapper->SetInputConnection(lineSource->GetOutputPort());
	mapper->Update();
	renderWindow->AddRenderer(renderer);
	renderWindow->SetInteractor(renderWindowInteractor);
	actor->SetMapper(mapper);
	renderer->AddActor(actor);

	QObject::connect(pushButton, &QPushButton::released, [&]() {
	
		QString text2 = QInputDialog::getText(nullptr, "Input File Name to be Read", "File Name");
		qDebug() << "Input: " << text2;
		char read[100];

		qstrcpy(read, qPrintable(text2));


		ReadFile(read);
		SetFirstPoint();
		SetSecondPoint();
		
		mapper->Update();
		actor->SetMapper(mapper);
		renderer->AddActor(actor);
		vtkRenderWidget->update();
		renderWindowInteractor->Initialize();
		renderWindow->Render();
		});
	
	
	QObject::connect(pushButton2, &QPushButton::released, [&]() {
		QString text = QInputDialog::getText(nullptr, "Input File Name to be written", "File Name");
		qDebug() << "Input: " << text;
		string write;
		write = text.toStdString();
		write = write + ".txt";
		WriteFile(write); });


	vtkNew<vtkNamedColors> colors;





	vtkNew<vtkNamedColors> namedColors;






	actor->GetProperty()->SetLineWidth(spinBox->value());
	cout << "color  " << selectedText.toStdString();
	cout << "Linewidth  " << spinBox->value();
	actor->GetProperty()->SetColor(colors->GetColor3d(selectedText.toStdString()).GetData());
	/*for(int i=0;i<101;i++){
		string getcolor = actor->GetProperty()->GetColor();
	LineColor[i] = )[i];
	if (LineColor[i] == NULL) {
		break;
	}

	}*/



	renderer->SetBackground(namedColors->GetColor3d("SlateGray").GetData());

	QObject::connect(comboBox, (&QComboBox::currentIndexChanged), [&]() {


		selectedText = comboBox->currentText(); // update selectedText with the current selected item
		actor->GetProperty()->SetColor(colors->GetColor3d(selectedText.toStdString()).GetData());
		qstrcpy(LineColor, qPrintable(selectedText));



		renderWindow->Render();
		});

	QObject::connect(spinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), [&]() {
		actor->GetProperty()->SetLineWidth(spinBox->value());
		LineWidth = spinBox->value();
		renderWindow->Render();
		});


	//Connect renderWindowInteractor in ONLeftClick with current working interactor
	renderWindow->SetInteractor(renderWindowInteractor);

	mainWindow.setCentralWidget(vtkRenderWidget);

	renderWindow->AddRenderer(renderer);
	renderWindow->SetInteractor(vtkRenderWidget->interactor());

	renderWindow->GetInteractor()->SetPicker(pointPicker);
	vtkNew<MouseInteractorStylePP> style;
	renderWindow->GetInteractor()->SetInteractorStyle(style);



	vtkRenderWidget->setRenderWindow(renderWindow);

	//vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	//renderWindowInteractor->SetPicker(pointPicker);
	//renderWindowInteractor->SetRenderWindow(renderWindow);


	//renderWindowInteractor->SetInteractorStyle(style);



	// Display the line
	renderWindow->Render();


	renderWindow->GetInteractor()->Start();

	mainWindow.show();
	return app.exec();


}


// VTK part
