pipeline {
    agent none
    stages {
        stage('Check norme') {
            agent {docker 'epitechcontent/epitest-docker:latest'}
            steps {
                sh 'uname -a'
                sh 'pwd '
                sh 'mkdir -p build && cd build && cmake .. && make'
                sh 'pwd '
            }
        }

    }
}
