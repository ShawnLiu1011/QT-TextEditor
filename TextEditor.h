#include <QMainWindow>

#include <QTextEdit>
#include <QPrintDialog>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QtWidgets>
#include <QCloseEvent>  

class TextEditor : public QMainWindow
{
	Q_OBJECT

public:
	TextEditor(QWidget *parent = Q_NULLPTR);
	~TextEditor();

private:
	QString currentFileName;
	bool fileSaved;

	void createMenus();
	void createActions();
	void createToolBars();
	void createStatusBar();
	void setDefaultFormat();
	bool save(QString);
	bool loadFile(QString);
	QTextEdit *edit;
	QMenu *fileMenu;        //文件菜单
	QMenu *editMenu;        //编辑菜单
	QMenu *formatMenu;      //格式菜单
	QMenu *fontMenu;        //字体子菜单
	QMenu *helpMenu;        //帮助菜单
							//【文件】主菜单
	QAction *newAct;        //新建
	QAction *openAct;       //打开
	QAction *saveAct;       //保存
	QAction *saveAsAct;     //另存为
	QAction *printAct;      //打印
	QAction *printPreviewAct;//打印预览
	QAction *quitAct;       //退出
							//【编辑】主菜单
	QAction *undoAct;       //撤销
	QAction *redoAct;       //重做
	QAction *cutAct;        //剪切
	QAction *copyAct;       //复制
	QAction *pasteAct;      //粘贴
							//【格式】主菜单
	QAction *boldAct;       //加粗
	QAction *italicAct;     //倾斜
	QAction *underlineAct;  //下划线
	QAction *colorAct;      //颜色
							//【帮助】主菜单
	QAction *aboutAct;      //关于本软件
	QAction *aboutQtAct;    //关于Qt
	
	QToolBar *fileToolBar;  //"文件"工具条
	QToolBar *editToolBar;  //"编辑"工具条
	QToolBar *formatToolBar;//"格式"工具条

	private slots:
	void contentChanged();
	void about();
	void fileNew();                         //新建文件操作
	void fileOpen();                        //打开文件操作
	bool fileSave();                        //保存文件操作
	bool fileSaveAs();                      //另存为文件操作
	void fileClose();
	void undo();                            //撤销
	void redo();                            //重做
	void cut();                             //剪切
	void copy();                            //复制
	void paste();                           //粘贴
	void textBold();                        //加粗
	void textItalic();                      //倾斜
	void textUnderline();                   //下划线
	void textColor();                       //设置字体颜色
	void filePrint();                       //打印文档
	void filePrintPreview();                //打印预览文档
	void printPreview(QPrinter *printer);
protected:
	void closeEvent(QCloseEvent *event);
};