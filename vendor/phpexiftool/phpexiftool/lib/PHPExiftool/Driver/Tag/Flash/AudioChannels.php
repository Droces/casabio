<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Flash;

use PHPExiftool\Driver\AbstractTag;

class AudioChannels extends AbstractTag
{

    protected $Id = 'Bit7';

    protected $Name = 'AudioChannels';

    protected $FullName = 'Flash::Audio';

    protected $GroupName = 'Flash';

    protected $g0 = 'Flash';

    protected $g1 = 'Flash';

    protected $g2 = 'Audio';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'Audio Channels';

    protected $Values = array(
        1 => array(
            'Id' => 1,
            'Label' => '1 (mono)',
        ),
        2 => array(
            'Id' => 2,
            'Label' => '2 (stereo)',
        ),
    );

}
