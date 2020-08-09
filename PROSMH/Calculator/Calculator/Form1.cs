using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{

    public partial class Form1 : Form
    {
        int sum1;
        int sum2;
        int i, j;
        int result;
        int min1;
        
        public Form1()
        {
            InitializeComponent();
           
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }

        private void buton_ayikla(object sender , EventArgs e)
        {
            Button newBtn = (Button)sender;
            textBox1.Text += newBtn.Name.Substring(2,newBtn.Name.Length-2);
        }


        private void button1_Click_1(object sender, EventArgs e)
        {
        }

        private void button10_Click(object sender, EventArgs e)
        {
        }

        private void button11_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != null)
            {
                sum1 = Convert.ToInt32(textBox1.Text);
                i = 1;
                textBox1.Text = null;
            }
            else if(textBox1.Text == null)
            {
                sum1 = 0;
                i = 0;
            }

        }

        private void button12_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != null)
            {
                min1 = Convert.ToInt32(textBox1.Text);
                j = 1;
                textBox1.Text = null;            }
            else if(textBox1.Text == null)
            {
                min1 = 0;
                j = 0;
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
        }

        private void button2_Click(object sender, EventArgs e)
        {
        }

        private void button3_Click(object sender, EventArgs e)
        {
        }

        private void button6_Click(object sender, EventArgs e)
        {
        }

        private void button8_Click(object sender, EventArgs e)
        {
        }

        private void button5_Click(object sender, EventArgs e)
        {
        }

        private void button6_Click_1(object sender, EventArgs e)
        {
        }

        private void button7_Click(object sender, EventArgs e)
        {

        }

        private void button9_Click(object sender, EventArgs e)
        {

        }

        private void button10_Click_1(object sender, EventArgs e)
        {
            if(i == 1)
            {
                textBox1.Text = Convert.ToString(sum1 + Convert.ToInt32(textBox1.Text));
                i = 0;
            }
            else if(j == 1)
            {
                textBox1.Text = Convert.ToString(min1 - Convert.ToInt32(textBox1.Text));
                j = 0;
            }
        }

        private void button11_Click_1(object sender, EventArgs e)
        {
            textBox1.Text = null;
        }
    }
}
