using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MaterialSkin.Controls;
using MaterialSkin;

using AForge.Video.DirectShow;
using AForge.Video;

namespace WindowsFormsApp1
{
    public partial class Form1 : MaterialForm
    {
        public Form1()
        {
            InitializeComponent();

            var materialSkinManager = MaterialSkinManager.Instance;
            materialSkinManager.AddFormToManage(this);
            materialSkinManager.Theme = MaterialSkinManager.Themes.LIGHT;
            materialSkinManager.ColorScheme = new ColorScheme(Primary.BlueGrey800, Primary.BlueGrey900, Primary.BlueGrey500, Accent.LightBlue200, TextShade.WHITE);
        }


        private void ChooseImage_Click(object sender, EventArgs e)
        {
            DialogResult result =  openFileDialog1.ShowDialog();
            if (result == DialogResult.OK)
            {
                /*Lay ten File da chon*/
                string nameOfImageFile = openFileDialog1.FileName;
                /*Khoi tao doi tuong Bitmap voi File da chon*/
                Bitmap imageBmp = new Bitmap(nameOfImageFile);
                /*Gan Bitmap de hien thi tam anh tren picturebox*/
                pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
                pictureBox1.Image = imageBmp;

                label1.Text = "";
                //materialLabel2.Text = nameOfImageFile;
            }
        }

        private void materialFlatButton2_Click(object sender, EventArgs e)
        {

        }

        private void materialListView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void folderBrowserDialog1_HelpRequest(object sender, EventArgs e)
        {
            
        }

        private void materialLabel1_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void materialFlatButton3_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {

        }

        private void Run_Click(object sender, EventArgs e)
        {
            if (videoSource == null)
                return;
            BTol.Btol btol = new BTol.Btol(videoFile.FileName);

            /* Delete Init Image if exist */
            /*
            if(pictureBox1.Image != null)
            {
                pictureBox1.Image.Dispose();
            }
            */
            

            /* Thuc hien phan tich ket qua video duoc chon */
            
            //btol.RunAnalysis(videoFile.FileName);

            Form2 runForm = new Form2();
            runForm.Show();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void materialLabel2_Click(object sender, EventArgs e)
        {

        }

        private void Play_Click(object sender, EventArgs e)
        {
            if (videoSource == null)
                return;
            videoSource.Start();
        }

        public FileVideoSource videoSource = null;
        public OpenFileDialog videoFile;

        private void ChooseVideo_Click(object sender, EventArgs e)
        {
            videoFile = new OpenFileDialog();
            DialogResult result = videoFile.ShowDialog();

            if( result == DialogResult.OK)
            {
                videoSource = new FileVideoSource(videoFile.FileName);
                videoSource.NewFrame += new NewFrameEventHandler( newFrameCallback );

                label1.Text = "";

                pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
                pictureBox1.ImageLocation = @"D:\Project\AnotationTool\BTol\WindowsFormsApp1\Resources\Play2.png";
                pictureBox1.Load();
            }
        }

        private void openFileDialog2_FileOk(object sender, CancelEventArgs e)
        {

        }

        //Bitmap currentFrame;
        //Bitmap tempFrame;
        //public bool firstFrame = true;

        private void newFrameCallback(object sender, NewFrameEventArgs eventFrame)
        {
            /* Realease previous Frame .. */
            releaseOldFrame();
            
            /* Display a new Frame */
            displayNewFrame(eventFrame);
        }

        private void displayNewFrame( NewFrameEventArgs eventFrame )
        {

            Bitmap newFrame = (Bitmap)eventFrame.Frame.Clone();
            pictureBox1.Image = newFrame;

            /*
            if ( firstFrame )
            {
                pictureBox1.Image.Dispose(); //Realease Background Image (PlayButton.png)

                tempFrame = (Bitmap)eventFrame.Frame.Clone();
                //currentFrame = new Bitmap(tempFrame);
                //tempFrame.Dispose();
                pictureBox1.Image = tempFrame;
                firstFrame =  false;

                return ;
            }

            pictureBox1.Image.Dispose();
            //currentFrame.Dispose();
            tempFrame = (Bitmap)eventFrame.Frame.Clone();
            //tempFrame = new Bitmap(tempFrame);
            //tempFrame.Dispose();
            pictureBox1.Image = tempFrame;
            */

        }

        
        private void releaseOldFrame()
        {
            pictureBox1.Image.Dispose();
        }
        

        private void Stop_Click(object sender, EventArgs e)
        {
            ExitVideo();
        }

        private void Pause_Click(object sender, EventArgs e)
        {
            
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            ExitVideo();
        }

        private void ExitVideo()
        {
            if (videoSource == null)
                return;
            if(videoSource.Source == "")
            {
                return;
            }

            videoSource.SignalToStop();
            for (int i = 0; i < 20; i++)
            {
                if (!videoSource.IsRunning)
                {
                    break;
                }
                System.Threading.Thread.Sleep(100);
            }

            if (videoSource.IsRunning)
            {
                videoSource.Stop();
            }
        }

        private void materialLabel1_Click_1(object sender, EventArgs e)
        {

        }

        private void materialFlatButton1_Click(object sender, EventArgs e)
        {
            BTol.Btol btolDebug = new BTol.Btol();
            btolDebug.Testing();
        }

        private void materialFlatButton9_Click(object sender, EventArgs e)
        {
            BTol.Btol btolTest = new BTol.Btol(@"C:\Users\PC\Downloads\Video\NgoaiHam.avi");
            btolTest.ApplyOtsuThresholdingAlgorithm();
        }
    }
}
