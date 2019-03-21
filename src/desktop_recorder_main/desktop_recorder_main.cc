#include "../include/desktop_recorder_main.h"
#include "ui_desktop_recorder_main.h"


DesktopRecorderMain::DesktopRecorderMain(QWidget *parent): QWidget (parent),
                                                           ui_(new Ui::DesktopRecorderMain)

{
    ui_->setupUi(this);

    ui_->stop_btn->hide();

    connect(ui_->start_btn, SIGNAL( clicked(bool)), SLOT(OnStartStop()));
    connect(ui_->stop_btn, SIGNAL( clicked(bool)), SLOT(OnStartStop()));

    connect(ui_->capture_cursor_chk_box, SIGNAL( clicked(bool) ), &recorder_, SLOT( EnableCursorCpature( bool ) ) );

    connect(&recorder_, SIGNAL(FrameAvailable(QImage)), SLOT(OnFrameAvailable(QImage)));
}

DesktopRecorderMain::~DesktopRecorderMain()
{
    delete ui_;
}

void DesktopRecorderMain::OnStartStop()
{
    ui_->start_btn->isVisible() ? recorder_.Start() : recorder_.Stop();
    ui_->start_btn->setVisible(!ui_->start_btn->isVisible());
    ui_->stop_btn->setVisible(!ui_->stop_btn->isVisible());
}

void DesktopRecorderMain::OnFrameAvailable(const QImage &img)
{
    ui_->view_lbl->setPixmap(QPixmap::fromImage(img).scaled(ui_->view_lbl->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation ) );
}
