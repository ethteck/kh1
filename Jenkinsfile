pipeline {
    agent {
        label 'kh1'
    }

    stages {
        stage('Setup') {
            steps {
                sh 'cp /usr/local/etc/roms/SLPS_251.98 .'
                sh 'cp /usr/local/etc/roms/SLPS_251.05 .'
                sh 'pip install -U -r requirements.txt --break-system-packages'
                // The build is sensitive to these; log them so a mismatch that
                // only reproduces here can be told apart from a local one.
                sh '''
                    mips-linux-gnu-as --version | head -1
                    mips-linux-gnu-ld --version | head -1
                    cpp --version | head -1
                '''
            }
        }
        stage('Build JP') {
            steps {
                sh './configure.py -v jp'
                sh 'ninja'
            }
        }
        stage('Build Final Mix') {
            steps {
                sh './configure.py -v fm'
                sh 'ninja'
            }
        }
        // stage('Report Progress') {
        //     when {
        //         branch 'main'
        //     }
        //     steps {
        //         withCredentials([string(credentialsId: 'pokemonsnap_frogress', variable: 'frogress_key')]) {
        //             sh 'python3 tools/progress.py --frogress $frogress_key'
        //         }
        //     }
        // }
    }
    post {
        failure {
            sh './tools/romdiff.py'
        }
        // Runs after the other post conditions, so `failure` still has a
        // workspace to inspect.
        cleanup {
            cleanWs()
        }
    }
}
