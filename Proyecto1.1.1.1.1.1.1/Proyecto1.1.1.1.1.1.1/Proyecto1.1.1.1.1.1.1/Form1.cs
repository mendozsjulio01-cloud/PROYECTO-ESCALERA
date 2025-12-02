using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Proyecto1._1._1._1._1._1._1
{
    public partial class Form1 : Form
    {
        System.IO.Ports.SerialPort Arduino;

        Color myRed = Color.FromArgb(255, 85, 121);

        public Form1()
        {
            InitializeComponent();

            Arduino = new SerialPort("COM3", 9600);

            // ---- AGREGADO ----
            Arduino.DataReceived += Arduino_DataReceived;
            // ------------------

            Arduino.Open();

            try
            {
                string[] availablePorts = SerialPort.GetPortNames();
                comboBoxPortSelection.DataSource = availablePorts;

                string[] rates = { "9600", "38400", "57600", "115200", "250000" };
                comboBoxBaudRate.DataSource = rates;

                timer1.Interval = 1000;
                timer1.Start();
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }

        // ============================================================
        //  NUEVA FUNCIÓN: Recibir datos del Arduino
        // ============================================================
        private void Arduino_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                string mensaje = Arduino.ReadLine().Trim();

                // Invocar al hilo gráfico
                this.Invoke(new Action(() =>
                {
                    ProcesarMensaje(mensaje);
                }));
            }
            catch
            {
                // Evitar errores silenciosos
            }
        }

        // ============================================================
        //   NUEVA FUNCIÓN: Procesar mensajes recibidos
        // ============================================================
        private void ProcesarMensaje(string mensaje)
        {
            // Siempre agregar a la ListBox SIN modificar nada más
            listBox1.Items.Add(mensaje);

            // Aquí puedes poner acciones extra si quieres...
            if (mensaje == "EQUIPO 1")
            {
                // Equipo rojo
            }
            else if (mensaje == "EQUIPO 2")
            {
                // Equipo verde
            }
            else if (mensaje == "EQUIPO 3")
            {
                // Equipo azul
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            labelClockRealTime.Text = DateTime.Now.ToString("HH:mm:ss");
        }

        private void pictureBoxMinimizeBtn_Click_Click(object sender, EventArgs e)
        {
            Form1.ActiveForm.WindowState = FormWindowState.Minimized;
        }

        private void pictureBoxCloseBtn_Click_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            String[] ports = SerialPort.GetPortNames();
            comboBoxPortSelection.DataSource = ports;
        }

        private void Led1_Click(object sender, EventArgs e)
        {
            Arduino.Write("E");
        }

        private void Led2_Click(object sender, EventArgs e)
        {
            Arduino.Write("I");
        }

        private void Led3_Click(object sender, EventArgs e)
        {
            Arduino.Write("U");
        }

        private void Apagado_Click(object sender, EventArgs e)
        {
            Arduino.Write("F");
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
