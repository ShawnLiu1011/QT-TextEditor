#include "TextEditor.h"

class QString rsrcPath = ":/icons/icons/";

TextEditor::TextEditor(QWidget *parent)
	: QMainWindow(parent)
{
	this->setWindowTitle(tr("Text Editor"));
	edit = new QTextEdit();
	this->setCentralWidget(edit);

	createActions();
	createMenus();
	createToolBars();
	createStatusBar();
}

TextEditor:: ~TextEditor()
{
}

void TextEditor::createMenus()
{
	//"文件"主菜单
	fileMenu = this->menuBar()->addMenu(tr("File"));
	fileMenu->addAction(newAct);
	fileMenu->addAction(openAct);
	fileMenu->addSeparator();  //分割线
	fileMenu->addAction(saveAct);
	fileMenu->addAction(saveAsAct);
	fileMenu->addSeparator();  //分割线
	fileMenu->addAction(printAct);
	fileMenu->addAction(printPreviewAct);
	fileMenu->addSeparator();  //分割线
	fileMenu->addAction(quitAct);
	//“编辑”主菜单
	editMenu = this->menuBar()->addMenu(tr("Edit"));
	editMenu->addAction(undoAct);
	editMenu->addAction(redoAct);
	editMenu->addSeparator();  //分割线
	editMenu->addAction(cutAct);
	editMenu->addAction(copyAct);
	editMenu->addAction(pasteAct);
	//"格式"主菜单
	formatMenu = this->menuBar()->addMenu(tr("Format"));
	fontMenu = formatMenu->addMenu(tr("Font"));      //"字体"子菜单
	fontMenu->addAction(boldAct);
	fontMenu->addAction(italicAct);
	fontMenu->addAction(underlineAct);
	formatMenu->addAction(colorAct);
	//”帮助“主菜单
	helpMenu = this->menuBar()->addMenu(tr("Help"));
	helpMenu->addAction(aboutAct);
	helpMenu->addSeparator();      //分割线
	helpMenu->addAction(aboutQtAct);
}

void TextEditor::createActions()
{
	//文件菜单动作集
	newAct = new QAction(QIcon(rsrcPath + "/new.png"), tr("New"), this);
	newAct->setShortcut(QKeySequence::New);
	newAct->setToolTip("New");              //设置工具栏按钮的提示文本
	newAct->setStatusTip("Create a new file");    //设置按钮状态栏提示文本
	connect(newAct, SIGNAL(triggered(bool)), this, SLOT(fileNew()));

	openAct = new QAction(QIcon(rsrcPath + "/open.png"), tr("Open"), this);
	openAct->setShortcut(QKeySequence::Open);
	openAct->setToolTip("Open");
	openAct->setStatusTip("Open a exist file");
	connect(openAct, SIGNAL(triggered(bool)), this, SLOT(fileOpen()));

	saveAct = new QAction(QIcon(rsrcPath + "/save.png"), tr("Save"), this);
	saveAct->setShortcut(QKeySequence::Save);
	saveAct->setToolTip("Save");
	saveAct->setStatusTip("Save current file");
	connect(saveAct, SIGNAL(triggered(bool)), this, SLOT(fileSave()));
	saveAsAct = new QAction(tr("Save As..."), this);
	saveAsAct->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_S);
	saveAsAct->setStatusTip(tr("Save current file as a new name"));
	connect(saveAsAct, SIGNAL(triggered(bool)), this, SLOT(fileSaveAs()));

	printAct = new QAction(QIcon(rsrcPath + "/print.png"), tr("Print"), this);
	printAct->setShortcut(QKeySequence::Print);
	printAct->setToolTip("Print");
	printAct->setStatusTip(tr("Print by a printer connected"));
	connect(printAct, SIGNAL(triggered(bool)), this, SLOT(filePrint()));
	printPreviewAct = new QAction(QIcon(rsrcPath + "/printPreview.png"), tr("Print Preview"), this);
	printPreviewAct->setStatusTip(tr("Preview before your printing"));
	connect(printPreviewAct, SIGNAL(triggered(bool)), this, SLOT(filePrintPreview()));

	quitAct = new QAction(QIcon(rsrcPath + "/exit.png"), tr("Exit"), this);
	quitAct->setShortcut(Qt::Key_Escape);
	quitAct->setStatusTip(tr("Exit Text Editor"));
	connect(quitAct, SIGNAL(triggered(bool)), this, SLOT(fileClose()));
	//编辑菜单动作集
	undoAct = new QAction(QIcon(rsrcPath + "/undo.png"), tr("Undo"), this);
	undoAct->setShortcut(QKeySequence::Undo);
	undoAct->setToolTip(tr("Undo"));
	undoAct->setStatusTip("Undo the operating");
	connect(undoAct, SIGNAL(triggered(bool)), this, SLOT(undo()));

	redoAct = new QAction(QIcon(rsrcPath + "/redo.png"), tr("Redo"), this);
	redoAct->setShortcut(QKeySequence::Redo);
	redoAct->setToolTip(tr("Redo"));
	redoAct->setStatusTip(tr("Redo the operating"));
	connect(redoAct, SIGNAL(triggered(bool)), this, SLOT(redo()));

	cutAct = new QAction(QIcon(rsrcPath + "/cut.png"), tr("Cut"), this);
	cutAct->setShortcut(QKeySequence::Cut);
	cutAct->setToolTip(tr("Cut"));
	cutAct->setStatusTip(tr("Cut the text"));
	connect(cutAct, SIGNAL(triggered(bool)), this, SLOT(cut()));

	copyAct = new QAction(QIcon(rsrcPath + "/copy.png"), tr("Copy"), this);
	copyAct->setShortcut(QKeySequence::Copy);
	copyAct->setToolTip(tr("Copy"));
	copyAct->setStatusTip(tr("Copy the text"));
	connect(copyAct, SIGNAL(triggered(bool)), this, SLOT(copy()));

	pasteAct = new QAction(QIcon(rsrcPath + "/paste.png"), tr("Paste"), this);
	pasteAct->setShortcut(QKeySequence::Paste);
	pasteAct->setToolTip(tr("Paste"));
	pasteAct->setStatusTip(tr("Paste the text"));
	connect(pasteAct, SIGNAL(triggered(bool)), this, SLOT(paste()));
	//"格式"主菜单动作集
	boldAct = new QAction(QIcon(rsrcPath + "/bold.png"), tr("Bold"), this);
	boldAct->setCheckable(true);
	boldAct->setShortcut(Qt::CTRL + Qt::Key_B);
	boldAct->setToolTip(tr("Bold"));
	boldAct->setStatusTip(tr("Bold the text"));
	QFont bold;
	bold.setBold(true);
	boldAct->setFont(bold);
	connect(boldAct, SIGNAL(triggered(bool)), this, SLOT(textBold()));

	italicAct = new QAction(QIcon(rsrcPath + "/italic.png"), tr("Italic"), this);
	italicAct->setCheckable(true);
	italicAct->setShortcut(Qt::CTRL + Qt::Key_I);
	italicAct->setToolTip(tr("Italic"));
	italicAct->setStatusTip(tr("Italic the text"));
	QFont italic;
	italic.setItalic(true);
	italicAct->setFont(italic);
	connect(italicAct, SIGNAL(triggered(bool)), this, SLOT(textItalic()));

	underlineAct = new QAction(QIcon(rsrcPath + "/underline.png"), tr("Underline"), this);
	underlineAct->setCheckable(true);
	underlineAct->setShortcut(Qt::CTRL + Qt::Key_U);
	underlineAct->setToolTip(tr("Underline"));
	underlineAct->setStatusTip(tr("Add a underline to the text"));
	QFont underline;
	underline.setUnderline(true);
	underlineAct->setFont(underline);
	connect(underlineAct, SIGNAL(triggered(bool)), this, SLOT(textUnderline()));

	colorAct = new QAction(QIcon(rsrcPath + "/color.png"), tr("Color..."), this);
	colorAct->setToolTip("Color");
	colorAct->setStatusTip(tr("Set text color"));
	connect(colorAct, SIGNAL(triggered(bool)), this, SLOT(textColor()));

	//"帮助"主菜单动作集
	aboutAct = new QAction(tr("About"), this);
	aboutAct->setStatusTip(tr("Myself Word"));
	connect(aboutAct, SIGNAL(triggered(bool)), this, SLOT(about()));
	aboutQtAct = new QAction(QIcon(rsrcPath + "/aboutQt.png"), tr("About Qt"), this);
	aboutQtAct->setStatusTip(tr("Qt library"));
	connect(aboutQtAct, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));

	connect(edit, SIGNAL(textChanged()), this, SLOT(contentChanged()));
}

void TextEditor::createToolBars()
{
	//”文件“工具栏
	fileToolBar = addToolBar(tr("File"));
	fileToolBar->addAction(newAct);
	fileToolBar->addAction(openAct);
	fileToolBar->addAction(saveAct);
	fileToolBar->addSeparator();   //分隔条
	fileToolBar->addAction(printAct);
	//”编辑“工具栏
	editToolBar = addToolBar(tr("Edit"));
	editToolBar->addAction(undoAct);
	editToolBar->addAction(redoAct);
	editToolBar->addSeparator();
	editToolBar->addAction(cutAct);
	editToolBar->addAction(copyAct);
	editToolBar->addAction(pasteAct);
	//”格式“工具条
	formatToolBar = addToolBar(tr("Format"));
	formatToolBar->addAction(boldAct);
	formatToolBar->addAction(italicAct);
	formatToolBar->addAction(underlineAct);
	formatToolBar->addSeparator();
	formatToolBar->addSeparator();
	formatToolBar->addAction(colorAct);
}
void TextEditor::createStatusBar()
{
	statusBar()->showMessage(tr("Ready"));
}


bool TextEditor::save(QString fileName)
{
	QTextDocumentWriter writer(fileName);
	return writer.write(edit->document());
}

bool TextEditor::loadFile(QString fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		return false;
	}
	QTextStream in(&file);
	edit->setText(in.readAll());
	return true;
}

void TextEditor::contentChanged()
{
	fileSaved = false;
}

void TextEditor::fileNew()
{
	if ((currentFileName == "" && !edit->toPlainText().isEmpty())
		|| (currentFileName != "" && !fileSaved))
	{
		int ans = QMessageBox::warning(this,
			"Warning", "Save the changes?",
			QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel);
		switch (ans)
		{
		case QMessageBox::Yes:
			fileSave();
			break;
		case QMessageBox::No:
			break;
		case QMessageBox::Cancel:
			return;
		}
	}
	setWindowTitle("Text Editor");
	edit->clear();
	fileSaved = false;
	currentFileName = "";
	setDefaultFormat();
}


void TextEditor::fileOpen()
{
	if ((currentFileName == "" && !edit->toPlainText().isEmpty())
		|| (currentFileName != "" && !fileSaved))
	{
		int ans = QMessageBox::warning(this,
			"Warning", "Save the changes?",
			QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel);
		switch (ans)
		{
		case QMessageBox::Yes:
			fileSave();
			break;
		case QMessageBox::No:
			break;
		case QMessageBox::Cancel:
			return;
		}
	}
	QString newName = QFileDialog::getOpenFileName(this, tr("Open"),
		QString(), tr("HTML document (*.html *.html);;all files(*.*)"));
	if (newName == "") return;
	else if (!loadFile(newName)) {
		QString warningMessage = "Cannot open file " + newName;
		QMessageBox::warning(this, tr("Error"), warningMessage);
		return;
	}
	currentFileName = newName;
	fileSaved = true;
	setWindowTitle(currentFileName + " - TextEditor");
	setDefaultFormat();
}//打开文件操作

bool TextEditor::fileSave()
{
	QString newName = currentFileName;
	if (newName == "")
		newName = QFileDialog::getSaveFileName(this, tr("Save"),
		QString(), tr("HTML document (*.html *.html);;all files(*.*)"));
	if (newName == "") return false;
	else if (!save(newName)) 
	{
		QString warningMessage = "Cannot save as " + newName;
		QMessageBox::warning(this, tr("Error"), warningMessage);
		return false;
	}
	fileSaved = true;
	currentFileName = newName;
	setWindowTitle(currentFileName + " - TextEditor");
	return true;
}                        //保存文件操作

bool TextEditor::fileSaveAs()
{
	QString newName = "";
	newName = QFileDialog::getSaveFileName(this, tr("Save"),
	QString(), tr("HTML document (*.html *.html);;all files(*.*)"));
	if (newName == "") return false;
	else if (!save(newName))
	{
		QString warningMessage = "Cannot save as " + newName;
		QMessageBox::warning(this, tr("Error"), warningMessage);
		return false;
	}
	fileSaved = true;
	currentFileName = newName;
	setWindowTitle(currentFileName + " - TextEditor");
	return true;
}                    //另存为文件操作

void TextEditor::filePrint()
{
	QPrinter printer(QPrinter::HighResolution);
	QPrintDialog *dlg = new QPrintDialog(&printer, this);
	if (edit->textCursor().hasSelection())
	{
		dlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
	}
	dlg->setWindowTitle(tr("打印文档"));
	if (dlg->exec() == QDialog::Accepted)
	{
		edit->print(&printer);
	}
	delete dlg;
}//打印文档
void TextEditor::filePrintPreview()
{
	QPrinter printer(QPrinter::HighResolution);
	QPrintPreviewDialog preview(&printer, this);
	connect(&preview, SIGNAL(paintRequested(QPrinter*)), SLOT(printPreview(QPrinter*)));
	preview.exec();
}//打印预览文档

void TextEditor::fileClose() 
{
	this->close();
}

void TextEditor::printPreview(QPrinter *printer)
{
	edit->print(printer);
}

void TextEditor::closeEvent(QCloseEvent *event)
{
	if ((currentFileName == "" && !edit->toPlainText().isEmpty())
		|| (currentFileName != "" && !fileSaved))
	{
		int ans = QMessageBox::warning(this,
			"Warning", "Save the changes?",
			QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel);
		switch (ans)
		{
		case QMessageBox::Yes:
			fileSave();
			break;
		case QMessageBox::No:
			break;
		case QMessageBox::Cancel:
			event->ignore();
			return;
		}
	}
}

void TextEditor::undo()
{
	edit->undo();
}                           //撤销
void TextEditor::redo()
{
	edit->redo();
}                                     //重做
void TextEditor::cut()
{
	edit->cut();
}                                       //剪切
void TextEditor::copy()
{
	edit->copy();
}                                    //复制
void TextEditor::paste()
{
	edit->paste();
}                                   //粘贴

void TextEditor::setDefaultFormat()
{
	QTextCharFormat fmt;
	fmt.setFontWeight(QFont::Normal);
	fmt.setFontPointSize(14);
	fmt.setFontItalic(false);
	fmt.setFontUnderline(false);
	edit->mergeCurrentCharFormat(fmt);
}

void TextEditor::textBold()
{
	QTextCharFormat fmt;
	fmt.setFontWeight(boldAct->isChecked() ? QFont::Bold : QFont::Normal);
	edit->mergeCurrentCharFormat(fmt);
}                                 //加粗
void TextEditor::textItalic()
{
	QTextCharFormat fmt;
	fmt.setFontItalic(italicAct->isChecked());
	edit->mergeCurrentCharFormat(fmt);
}                          //倾斜
void TextEditor::textUnderline()
{
	QTextCharFormat fmt;
	fmt.setFontUnderline(underlineAct->isChecked());
	edit->mergeCurrentCharFormat(fmt);
}                      //下划线

void TextEditor::textColor()
{
	QColor color = QColorDialog::getColor(edit->textColor(), this);
	//如果颜色无效
	if (!color.isValid())
	{
		return;
	}
	QTextCharFormat fmt;
	fmt.setForeground(color);
	edit->mergeCurrentCharFormat(fmt);
}//设置字体颜色

void TextEditor::about()
{
	QMessageBox::about(this, tr("About"), tr("Designed by Liu Xiaoyu. All rights reserved. "));
}