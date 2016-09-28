
import java.io.File;
import java.util.Calendar;

/*
 * �Q�l�y�[�W
 *  https://developers.google.com/youtube/v3/code_samples/java?hl=ja#upload_a_video 
 */

/*
 * �t�@�C���Ď�~youtube�A�b�v���[�h�܂ł̃v���Z�X�̐��������܂�
 * 1.temp�t�H���_����t�H���_�ɂ���
 * 2.video�t�H���_���Ď�(dirMonitor.start())�B�t�@�C�����ǉ����ꂽ��temp�Ɉړ�
 * 3.main�N���X��temp�t�H���_���Ď��B
 * 4.temp����t�H���_����Ȃ��Ȃ����炻�̃t�@�C���̃A�b�v���[�h�ɂ���
 * 5�D�A�b�v���[�h���I������炻�̃t�@�C��������1�ɖ߂�(2�ɂ��Ă͏�ɓ����Ă���)
 */

public class Mai_Uploader {
	public static void main(String[] args) {
		MyYouTube myYoutube = new MyYouTube();
		
		while(true){
			// video�t�H���_����t�H���_����Ȃ��Ȃ�܂Ń��[�v
			File video = new File("./video");
			// video�t�H���_�ɓ����Ă���t�@�C���̃��X�g
			String[] fileList = video.list();
			while(fileList.length == 0){
				fileList = video.list();
				myYoutube.sleep(5000);
			}
			myYoutube.sleep(5000);
			
			try {
				// �t�@�C���ɏ���ǉ�����
				myYoutube.setMetadata(
						fileList[0],
						"Mai_Uploader test upload on " + Calendar.getInstance().getTime(),
						"Mai_Uploader test upload on " + Calendar.getInstance().getTime()
						);
				new File(fileList[0]).delete();
				myYoutube.sleep(5000);
			} catch (Exception e) {
				e.printStackTrace();
				System.exit(0);
			}
		}
 	}
}