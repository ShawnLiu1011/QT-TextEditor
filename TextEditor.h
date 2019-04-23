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
	QMenu *fileMenu;        //�ļ��˵�
	QMenu *editMenu;        //�༭�˵�
	QMenu *formatMenu;      //��ʽ�˵�
	QMenu *fontMenu;        //�����Ӳ˵�
	QMenu *helpMenu;        //�����˵�
							//���ļ������˵�
	QAction *newAct;        //�½�
	QAction *openAct;       //��
	QAction *saveAct;       //����
	QAction *saveAsAct;     //���Ϊ
	QAction *printAct;      //��ӡ
	QAction *printPreviewAct;//��ӡԤ��
	QAction *quitAct;       //�˳�
							//���༭�����˵�
	QAction *undoAct;       //����
	QAction *redoAct;       //����
	QAction *cutAct;        //����
	QAction *copyAct;       //����
	QAction *pasteAct;      //ճ��
							//����ʽ�����˵�
	QAction *boldAct;       //�Ӵ�
	QAction *italicAct;     //��б
	QAction *underlineAct;  //�»���
	QAction *colorAct;      //��ɫ
							//�����������˵�
	QAction *aboutAct;      //���ڱ����
	QAction *aboutQtAct;    //����Qt
	
	QToolBar *fileToolBar;  //"�ļ�"������
	QToolBar *editToolBar;  //"�༭"������
	QToolBar *formatToolBar;//"��ʽ"������

	private slots:
	void contentChanged();
	void about();
	void fileNew();                         //�½��ļ�����
	void fileOpen();                        //���ļ�����
	bool fileSave();                        //�����ļ�����
	bool fileSaveAs();                      //���Ϊ�ļ�����
	void fileClose();
	void undo();                            //����
	void redo();                            //����
	void cut();                             //����
	void copy();                            //����
	void paste();                           //ճ��
	void textBold();                        //�Ӵ�
	void textItalic();                      //��б
	void textUnderline();                   //�»���
	void textColor();                       //����������ɫ
	void filePrint();                       //��ӡ�ĵ�
	void filePrintPreview();                //��ӡԤ���ĵ�
	void printPreview(QPrinter *printer);
protected:
	void closeEvent(QCloseEvent *event);
};