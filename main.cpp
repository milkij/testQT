#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QPixmap>
#include <iostream>
#include <QPainter>
#include <QPaintEvent>


class ImageButton : public QPushButton
{
Q_OBJECT;
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;

public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown = false;
};

ImageButton::ImageButton(QWidget *parent)
{
    setParent(parent);
    setToolTip("Стоп");
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap("..//img//redButton.png");
    mButtonDownPixmap = QPixmap("..//img//greenButton.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}


void ImageButton::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const
{
    return QSize(100,100);
}

QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e)
{
    setDown();
}

void ImageButton::setDown()
{
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
}

void ImageButton::setUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}


class MYAPP
{
public:
    auto slider()
    {

        auto *slider = new QSlider(Qt::Horizontal);
        auto *spinbox = new QSpinBox();
        slider->setMinimum(0);
        slider->setMaximum(100);
        spinbox->setMinimum(0);
        spinbox->setMaximum(100);
        //
        QObject::connect(slider, &QSlider::valueChanged, spinbox, &QSpinBox::setValue);
        QObject::connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged),slider, &QSlider::setValue);
        slider->resize(500,100);
        spinbox->resize(100,50);
        spinbox->move(900,500);
        slider->move(300, 500);
        //
        slider->show();
        spinbox->show();

    }

    auto button()
    {

    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ImageButton redButton(nullptr);
    redButton.setFixedSize(100,100);
    redButton.move(1000,400);
    QObject::connect(&redButton, &QPushButton::clicked, [](){std::cout << "clicked\n";});
    redButton.show();
    return app.exec();

}


